/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:27:41 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/26 18:29:06 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


// Copy Path libft.h 
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

# include "/Users/mmensing/Desktop/42/PRINTF/ft_printf.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


// my_func.c header -> unnötig oder?
//# include "/Users/mariemensing/LIBFT/my_libft_tester/MY_libft/libft.h"


# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

//colour shit
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"

# define DUN    "\x1B[38m"

# define RESET "\x1B[0m"

# define BOLD  "\033[1m"
# define UNDERLINE  "\033[4m"



#endif