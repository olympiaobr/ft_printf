#include "ft_printf.h"

void ft_prtint(int nb, int *len)
{
    if (nb == -2147483648)
    {
        ft_prtchar('-', len);
        ft_prtchar('2', len);
        ft_prtint(147483648, len);
    }
    else if (nb < 0)
    {
        nb = -nb;
        ft_prtchar('-', len);
        ft_prtint(nb, len);
    }
    else if (nb > 9)
    {
        ft_prtint(nb / 10, len);
        ft_prtint(nb % 10, len);
    }
    else
    {
        ft_prtchar(nb + '0', len);
    }
}
