/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:45:23 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/25 18:32:19 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


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

int percent_func(char type_letter, va_list args)
{
	if (type_letter == 'c')
		return(c_type_func(va_arg(args, int)));
	if (type_letter == 's')
		return(s_type_func(va_arg(args, char*)));
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
			i += percent_func(string[i + 1], args); // +1 so direct check for type
		}
		i++;
	}
	return (10);
}

int main()
{
	// char character = 'w';
	// ft_printf("content: %c\n", character);
	char *string = "bullshit";
	ft_printf("content: %s\n", string);
	// char character = 'P';
	// printf("content\n");
}