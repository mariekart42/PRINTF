/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:30:17 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/29 00:35:42 by mmensing         ###   ########.fr       */
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


// lib funcs -> später löschen und library includen
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_strchr(const char *str, int c);
void *ft_memmove(void *str_1, const void *str_2, size_t n);


// p
int p_type_func(unsigned long long string);
int      p_convert_func(unsigned long int nbr, char letter);
int len_func_p(unsigned long int nbr);

// x & X
int len_func_hex(unsigned int nbr);
int      x_X_type_func(unsigned int nbr, char letter);

// u
int len_func_u(unsigned int nbr);
int      u_type_func(unsigned int nb);

// i & d
int len_func_i_d(int long nb);
int      i_d_type_func(int long nb);

// c & s
int c_type_func(char character);
int s_type_func(char *string);

#endif