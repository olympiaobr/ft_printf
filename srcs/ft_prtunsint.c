#include "ft_printf.h"

void ft_prtunsint(unsigned int number, int *len)
{
    if (number / 10 != 0)
        ft_prtunsint(number / 10, len);

    ft_prtunsint(number % 10 + '0', len);
}
