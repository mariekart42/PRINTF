/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:30:17 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/28 16:57:14 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/_types/_va_list.h>
#include <unistd.h>

int ft_printf(const char *string, ...);
char	*ft_strchr(const char *str, int c);
void *ft_memmove(void *str_1, const void *str_2, size_t n);

char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
int	len_func(int n);


#endif