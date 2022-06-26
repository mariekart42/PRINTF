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
