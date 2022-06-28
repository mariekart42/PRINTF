#include "ft_printf.h"

int len_func_u(unsigned int nbr)
{
	int i = 0;
	if(nbr == 0)
		return(1);
	while(nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return(i);
}

// prints unsigned integer base 10 %u
int      u_type_func(unsigned int nb)
{
	unsigned int ori;
	
	ori = nb;
     if (nb < 0)
     {
          write (1, "-", 1);
          nb *= -1;
     }
     if (nb > 9)
     {
          u_type_func (nb / 10);
          u_type_func (nb % 10);
     }
     if (nb <= 9)
     {
          nb = nb + '0';
          write (1, &nb, 1);
     }
	return (len_func_u(ori));
}