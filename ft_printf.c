/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:45:23 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/26 12:19:36 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include<float.h>

// how to hanlde % if eg. ft_printf("...%..."); ?? error and what to return
// do we have to handle eg. ft_printf("float: 0.4f", float_num);
// are we allowed to use macros??

// print character %c
int c_type_func(int character)
{
	write(1, &character, 1);
	return(1);
}


// print string %s
int s_type_func(char *string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
	return(1);
}

// print void* into hex format %p
int p_type_func(void *string)
{
	//convert to hex
	return (1);
}

// prints integer base 10 %i
int      i_type_func(int nb)
{
     if (nb == -2147483648 )
     {
          write (1, "-2147483648", 11);
          return (1);
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
	return (1);
}

// // prints decimal base 10 %d
// int      d_type_func(float nb)
// {
//      if (nb == FLT_MIN )
//      {
//           write (1, "-2147483648", 11);
//           return (1);
//      }
//      if (nb < 0)
//      {
//           write (1, "-", 1);
//           nb *= -1;
//      }
//      if (nb > 9)
//      {
//           i_type_func (nb / 10.0);
//           i_type_func (nb % 10.0);
//      }
//      if (nb <= 9)
//      {
//           nb = nb + '0';
//           write (1, &nb, 1);
//      }
// 	return (1);
// }

// prints lowercase hexadecimal %x
int      x_type_func(int long nbr)
{
     int long       k;

     if(nbr < 0)
     {
          nbr *= -1;
          write (1, "-", 1);
     }
     if (nbr >= 16)                         //16 cause F is 15
     {
          x_type_func (nbr / 16);
          x_type_func (nbr % 16);
     }
     if (nbr < 16 && nbr > 9)
     {
          nbr = nbr + 7 + '0';
          write (1, &nbr , 1);
     }
     if (nbr < 16)
     {
          nbr = nbr + '0';
          write (1, &nbr, 1);
     }
     return(1);
}
int percent_func(char type_letter, va_list args)
{
	if (type_letter == 'c')	
		return(c_type_func(va_arg(args, int)));
	if (type_letter == 's')
		return(s_type_func(va_arg(args, char*)));
	if (type_letter == 'p')
		return(p_type_func(va_arg(args, void*)));
	// if (type_letter == 'd')
	// 	// %d Prints a decimal (base 10) number
	// if (type_letter == 'i')
	// 	return(i_type_func(va_args(args, int)));
	// if (type_letter == 'u')
	// 	//%u Prints an unsigned decimal (base 10) number
	if (type_letter == 'x')
		return(x_type_func(va_args(args, int)));
	// if (type_letter == 'X')
	// 	//v%X Prints a number in hexadecimal (base 16) uppercase format
	// if (type_letter == '%')
	// 	//%% Prints a percent sign
	return(0);
}

int ft_printf(const char *string, ...)
{
	int i = 0;
	
	va_list args;
	
	va_start(args, string);
	
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			if (ft_strchr("cspdiuxX", string[i + 1]) == NULL && string[i+1] != '%') // error
				return (-1); // what to return??
			i += percent_func(string[i + 1], args);
		}
		i++;
	}
	return (10);
}

int main()
{
	// char character = 'w';
	// ft_printf("content: %c\n", character);
	// char *string = "bullshit";
	// ft_printf("content: %s\n", string);
	// char character = 'P';
	// printf("content\n");
	int hex = 12;
	ft_printf("hex: %x\n", hex);
}