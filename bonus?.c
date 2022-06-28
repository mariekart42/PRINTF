/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus?.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:45:23 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/29 01:57:00 by mmensing         ###   ########.fr       */
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

// negative hex: 




void print_special_flag(char flag, int long val)
{
	if (flag == ' ')
	{
		if (val >= 0)
			write(1, " ", 1);
	}
	if (flag == '+')
	{
		if (val >= 0)
			write(1, "+", 1);
		if (val < 0)
			write(1, "-", 1);
	}
}

int percent_func(const char *type_letter, va_list args)
{
	int d_i_plus_1 = 0;
	if (type_letter[1] == 'd' || type_letter[1] == 'i')
		d_i_plus_1 = 1;
	int d_i = 0;
	if (type_letter[0] == 'd' || type_letter[0] == 'i')
		d_i = 1;
		
	int check_flag;
	check_flag = 0;
	int val;

	if (*type_letter == 'c')	
		return(c_type_func(va_arg(args, int)));
	if (*type_letter == 's')
		return(s_type_func(va_arg(args, char*)));
	if (*type_letter == 'p')
		return(p_type_func(va_arg(args, unsigned long long)));
	if (d_i == 1 || ((d_i_plus_1 == 1 && type_letter[0] == '+') || (d_i_plus_1 == 1 && type_letter[0] == ' ')))
	{
		val = va_arg(args, int);
		//check_flag = print_special_flag((char *)type_letter, val);
		if (d_i_plus_1 == 1)
		{
			print_special_flag(type_letter[1], val);
			check_flag+=1;
		}
		return (i_d_type_func(val) + check_flag);
	}
	if (*type_letter == 'u')
		return(u_type_func(va_arg(args, unsigned int)));
	if (*type_letter == 'x')
		return(x_X_type_func(va_arg(args, int), 'x'));
	if (*type_letter == 'X')
		return(x_X_type_func(va_arg(args, int), 'X'));
	if (*type_letter == '%')
	{
		write(1, "%%", 1);
		return(1);
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
			// if ((ft_strchr("cspdiuxX", string[i + 1]) == NULL) && (string[i + 1] != '%')) // error
			// {
			// 	i += check_special_flags(string[i+1], args);
			// }
			count += percent_func(string + 1 + i, args);
			i++;
			if(string[i+1] == ' ' || string[i+1] == '+')
				i++;
		}
		else
     		count += write(1, &string[i], 1);
     	i++;
	}
	va_end(args);
	return (count);
}

// int main(void)
// {
// 	int val = 0;
	
// 	val = printf("%+dX", 1);
// 	printf("\nori_val_1: %d\n", val);
	
// 	val = printf("%+dX",-1);
// 	printf("\nori_val_2: %d\n", val);
	
// 	// val = 0;
// 	// printf("\n");
	
// 	// val = ft_printf("% dX", 10);
// 	// printf("\nmine_val_1: %d\n", val);

// 	// val = ft_printf("% dX", -10);
// 	// printf("\nmine_val_2: %d\n", val);
// }



// + - for: d, i		-> prints - before neg number, + befor pos number
// space flag for: d, i	-> prints space before positive number (not before neg)