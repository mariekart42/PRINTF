/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:07:08 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/25 17:27:21 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int ft_printf(const char *string, ...);
char	*ft_strchr(const char *str, int c);
void *ft_memmove(void *str_1, const void *str_2, size_t n);

#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/_types/_va_list.h>
#include <unistd.h>
#endif