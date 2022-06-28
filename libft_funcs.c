/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:57:54 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/28 16:57:04 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void *ft_memmove(void *str_1, const void *str_2, size_t n)
{
     size_t	i;
	unsigned char	*st_1;
	unsigned char	*st_2;

     i = 0;
     if (!str_1 && !str_2)
          return (NULL);
	st_1 = (unsigned char *)str_1;
	st_2 = (unsigned char *)str_2;
	if (str_1 > str_2)
	{
		while (n-- > 0)
			st_1[n] = st_2[n];
	}
	else
	{
		while (i < n)
		{
			st_1[i] = st_2[i];
			i++;
		}
	}
	return (str_1);
}

/**
 * @brief   function searches for the FIRST occurrence in str for character c
            if str doesnt end with NUL program might crash 
 * @param str string where c should get found
 * @param c the character we are searching for 
 * @return char*    returns pointer to string at the position where 'c' was found
                    returns NULL if not found
 */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str[0] == (char) c)
		return ((char *) str);
	while (str[i] != '\0')
	{
		if ((c == '\0') && (str[i + 1] == '\0'))
			return ((char *) str + i + 1);
		if (str[i] == (char)c)
		{
			return ((char *) str + i);
		}
		i++;
	}
	return ((char *) '\0');
}


//------ itoa --------
/**
 * @brief converting integer into string
 * 
 * @param n integer that gets convertet
 * @return char pointer to string
 */
int	len_func(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*converting(int len, int p, char *ptr, int n)
{
	while (len + 1 > p)
	{
		if (n < 0)
			ptr[len] = n % 10 * (-1) + '0';
		else
			ptr[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		p;

	len = 0;
	len = len_func(n);
	ptr = (char *) malloc (len + 1);
	if (!ptr)
		return (NULL);
	p = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		p = 1;
	}
	ptr[len] = '\0';
	len--;
	return (converting(len, p, ptr, n));
}
//--------------------

/**
 * @brief function duplicates a string and return a pointer pointing to the 
 * first byte of copied string 
 * memory reserved with malloc
 * 
 * @param src pointer to string that gets copied
 * @return char* 
 */
char	*ft_strdup(char *src)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	size = ft_strlen(src) + 1;
	ptr = (char *) malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/**
 * @brief returns lengh of str
 * 
 * @param str 
 * @return size_t lengh of str
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


/**
 * @brief Outputs the character ’c’ to the given file descriptor
 * 
 * @param c character to output
 * @param fd given file descriptor
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}