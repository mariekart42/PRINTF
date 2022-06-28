#include "ft_printf.h"

int len_func_p(unsigned long int nbr)
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

// converts p into hex
int      p_convert_func(unsigned long int nbr, char letter)
{
	if (nbr >= 16)                         //16 cause F is 15
     {
          p_convert_func (nbr / 16, letter);
          p_convert_func (nbr % 16, letter);
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
     return(len_func_p(nbr));
}

// print void* into hex format %p
int p_type_func(unsigned long long string)
{
	int count;
	
	count = 0;
	count += write(1, "0x", 2);
	if (string == 0)
		return (count + write(1, "0", 1));
	else
		return (count + p_convert_func(string, 'x'));
}