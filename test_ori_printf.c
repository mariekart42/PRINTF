/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ori_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:43:41 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/27 21:37:43 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int main()
{
	void *p;
	int n;
	p = &n;
	// char *ptr = "bla";
	// p = *ptr;
	//show = &ptr;
	// write(1, &p, 10);
	int val;
	int num = 1012;
	val = printf("1234%d", num);
	printf("val: %d\n", val);
}