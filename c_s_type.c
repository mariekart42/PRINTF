#include "ft_printf.h"

// print character %c
int c_type_func(char character)
{
	return (write(1, &character, 1));
}

// print string %s
int s_type_func(char *string)
{
	int i;
	
	i = 0;
	if (!string)
		return (write(1, "(null)", 6));
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}
