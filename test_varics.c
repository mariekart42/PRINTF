/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_varics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:31:18 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/25 16:47:30 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <sys/_types/_va_list.h>
//The va_arg() macro returns a pointer to the next argument in list p.
//va_list is a complete object type suitable for holding the information 
//	needed by the macros va_start, va_copy, va_arg, and va_end

void print_int(char *num, ...)
{
	int i = 0;
	int val;
	
	va_list args;
	
	va_start(args, num);
	
	while (i < 5)
	{
		val = va_arg(args, int);
		printf("%d. val: %d\n", i, val);
		i++;
	}
	i=0;
	printf("second\n");
	va_start(args, num);
	while (i < 5)
	{
		val = va_arg(args, int);
		printf("%d. val: %d\n", i, val);
		i++;
	}
	va_end(args);
}

int main()
{
	printf("first:\n");
	print_int(3, 5, 9, 2, 4, 6);
	// printf("second:\n");
	// print_int(1, 4, 5, 4);
}