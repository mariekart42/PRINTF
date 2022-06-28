#include "ft_printf.h"

int len_func_i_d(int long nb)
{
	int len = 0;
	
	if (nb <= 0)
	{
		len++;
		nb *= -1;
	}
	while(nb > 0)
	{
		nb /= 10;
		len++;
	}
	return(len);
}

// prints integer base 10 %i
int      i_d_type_func(int long nb)
{
	int long ori;
	
	ori = nb;
	if (nb < 0)
     {
          write (1, "-", 1);
          nb *= -1;
     }
     if (nb > 9)
     {
          i_d_type_func (nb / 10);
          i_d_type_func (nb % 10);
     }
     if (nb <= 9)
     {
          nb = nb + '0';
          write (1, &nb, 1);
     }
	return (len_func_i_d(ori));
}
