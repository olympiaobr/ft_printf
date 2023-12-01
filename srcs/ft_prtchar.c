#include "libftprintf.h"

void ft_prtchar(char c, int *len)
{
    write(1, &c, 1);
    (*len)++;
}
