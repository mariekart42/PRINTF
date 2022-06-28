/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:45:23 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/28 01:46:41 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <float.h>
#include <stdio.h>
#include <unistd.h>

// how to hanlde % if eg. ft_printf("...%..."); ?? error and what to return
// are we allowed to use macros??
// %d and %i the fuggin same?

int c_type_func(char character);
int s_type_func(char *string);
int p_type_func(unsigned long long string);

int      x_type_func(int long nbr, int count);

// print character %c
int c_type_func(char character)
{
	return (write(1, &character, 1));
}

// print string %s
int s_type_func(char *string)
{
	int i;
	
	i = 0;
	if (!string)
		return (write(1, "(null)", 6));
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}

// print void* into hex format %p
int p_type_func(unsigned long long string)
{
	int count = 0;
	
	write(1, "0x", 2);
	count += x_type_func(string, count);
	count +=2;
     return (count);
	//return (2);
}

// prints integer base 10 %i
int      i_type_func(int nb)
{
     if (nb == -2147483648 )
     {
          write (1, "-2147483648", 11);
          return (2);
     }
     if (nb < 0)
     {
          write (1, "-", 1);
          nb *= -1;
     }
     if (nb > 9)
     {
          i_type_func (nb / 10);
          i_type_func (nb % 10);
     }
     if (nb <= 9)
     {
          nb = nb + '0';
          write (1, &nb, 1);
     }
	return (2);
}

// prints lowercase hexadecimal %x
int      x_type_func(int long nbr, int count)
{
	static int kount;
	
	kount = count;  
     // if(nbr < 0)
     // {
     //      nbr *= -1;
     //      kount +=write (1, "-", 1);
     // }
     if (nbr >= 16)                         //16 cause F is 15
     {
          x_type_func (nbr / 16, kount);
          x_type_func (nbr % 16, kount);
     }
     if (nbr < 16 && nbr > 9)
     {
          nbr = nbr + 39 + '0';//39 cause there are the lowercase letters -> ASCII
          kount += write (1, &nbr , 1);
     }
     if (nbr < 16)
     {
          nbr = nbr + '0';
          kount += write (1, &nbr, 1);
     }
	count = kount;
	kount = 0;
     return(count);
}

// prints uppercase hexadecimal %X
int      X_type_func(int long nbr, int count)
{
	static int kount;
	
	kount = count;  
     // if(nbr < 0)
     // {
     //      nbr *= -1;
     //      kount +=write (1, "-", 1);
     // }
     if (nbr >= 16)                         //16 cause F is 15
     {
          x_type_func (nbr / 16, kount);
          x_type_func (nbr % 16, kount);
     }
     if (nbr < 16 && nbr > 9)
     {
          nbr = nbr + 7 + '0';//39 cause there are the lowercase letters -> ASCII
          kount += write (1, &nbr , 1);
     }
     if (nbr < 16)
     {
          nbr = nbr + '0';
          kount += write (1, &nbr, 1);
     }
	count = kount;
	kount = 0;
     return(count);
}


// same as i_type_func i guess 
int d_type_func(int decimal)
{	
	i_type_func(decimal);
	return(2);
}

// prints unsigned integer base 10 %u
int      u_type_func(unsigned int nb)
{
     if (nb < 0)
     {
          write (1, "-", 1);
          nb *= -1;
     }
     if (nb > 9)
     {
          i_type_func (nb / 10);
          i_type_func (nb % 10);
     }
     if (nb <= 9)
     {
          nb = nb + '0';
          write (1, &nb, 1);
     }
	return (2);
}

int percent_func(const char type_letter, va_list args)
{
	int len;

	len = 0;
	if (type_letter == 'c')	
		return(c_type_func(va_arg(args, int)));
	if (type_letter == 's')
		return(s_type_func(va_arg(args, char*)));
	if (type_letter == 'p')
		return(p_type_func(va_arg(args, unsigned long long)));
	if (type_letter == 'd')
		return(d_type_func(va_arg(args, int)));
	if (type_letter == 'i')
		return(i_type_func(va_arg(args, int)));
	if (type_letter == 'u')
		return(u_type_func(va_arg(args, unsigned int)));
	if (type_letter == 'x')
		return(x_type_func(va_arg(args, int), 0));
	if (type_letter == 'X')
		return(X_type_func(va_arg(args, int), 0));
	if (type_letter == '%')
	{
		write(1, "%%", 1);
		return(2);
	}
	return(0);
}

int ft_printf(const char *string, ...)
{
	int i = 0; // only for iteration
	int count = 0; // what in the end gets returned
	
	va_list args;
	
	va_start(args, string);
	
	while (string[i])
	{
		if (string[i] == '%')
		{
			if ((ft_strchr("cspdiuxX", string[i + 1]) == NULL) && (string[i + 1] != '%')) // error
			{
				return (-1); // what to return??
			}
			count += percent_func(string[i + 1], args);
			i++;
		}
		else
     		count += write(1, &string[i], 1);
     	i++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	int val = 0;
// 	void *ptr;
// 	void *tt;
// 	val = printf("%p",(void *) -1);
// 	printf("\nval_1: %d\n", val);
// 	// val = printf("%p", tt);
// 	// printf("\nval_1: %d\n", val);
// 	val = 0;
// 	printf("\n");
// 	val = ft_printf("%p", (void *) -1);
// 	printf("\nval_1: %d\n", val);
// 	// val = ft_printf("%p", tt);
// 	// printf("\nval_1: %d\n", val);

// }

// int main()
// {
// 	ft_printf(" %c %c %c ", '2', '1', 0);
// // 	char character = 'w';
// 	int hex = 65535;
// 	char *string = "bullshit";
// 	int integer = 0123;
// 	double double_int = 123456789;
// 	double decimal = 420.20;
// 	unsigned int zero_to_big = -2;
    
// 	// printf("\nTESTER-ORI\n--------\nchar: \t%c\n", character); 
// 	// ft_printf("\nTESTER_MINE\n--------\nchar: \t%c\n", character); 
//     //  //write(1, void_ptr_2, 10);   
    
// 	int val;
// 	// val = printf("%c %c", '1', 9);
// 	// printf("|");
// 	// printf("\nval_1: %d\n", val);
// 	// // val = printf(" %c", '0');
// 	// // printf("\nval_2: %d\n", val);
// 	// val= 0;
// 	// printf("\n");
// 	val = ft_printf("%c %c", '1', 9);
// 	printf("|");
// 	printf("\nval_2: %d\n", val);
	
// 	// val = ft_printf(" %c ", '0');
	
// 	//printf("\nval_1: %d\n", val);
// 	printf("\n");
	
	
	
// 	//write(1, &void_ptr, 10);
// 	// int val = 0;
// 	// val = printf("(%d)\n", 2);
// 	// printf("ori_val: %d\n", val);
// 	// val = ft_printf("(%d)\n", 2);
// 	// printf("mine_val: %d\n", val);
// 	// ft_printf("hex: %x\n", hex);
// 	// printf("ori: %i\n", zero_to_big);
// 	// printf("ori: %d\n", zero_to_big);
	
// 	// ft_printf("mine: %d\n", zero_to_big);
// 	// ft_printf("mine: %i\n", zero_to_big);
	
// 	// printf("ori_percent: %%\n");
// 	// ft_printf("mine_percent: %%\n");
	
// 	// ft_printf("ori: %x\n", hex);
// 	//ft_printf("\nTYPES\n-----\ninteger:  %i\nchar:\t  %c\nhex_low:  %x \nhex_up:\t  %X\nstring:\t  %s\ndecimal:  %d\n\n", integer, character, hex, hex, string, decimal);
// }














