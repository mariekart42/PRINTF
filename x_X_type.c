#include "ft_printf.h"

int len_func_hex(unsigned int nbr)
{
	int i;
	
	i = 0;
	if (nbr == 0)
		return(1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while(nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

// prints lowercase AND uppercase hexadecimal %x & %X
int      x_X_type_func(unsigned int nbr, char letter)
{
	if (nbr >= 16)                         //16 cause F is 15
     {
          x_X_type_func (nbr / 16, letter);
          x_X_type_func (nbr % 16, letter);
     }
	else 
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
		{
			if (letter == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			if (letter == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
     return(len_func_hex(nbr));
}
