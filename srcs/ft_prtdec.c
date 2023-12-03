#include "ft_printf.h"

void	ft_prtdec(int nbr)
{
	long nb;
	char c;

	nb = nbr;
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_prtdec(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}
