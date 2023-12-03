#include "ft_printf.h"

void ft_prtstr(char *str, int *len)
{
    int i;

    if (str == NULL)
        ft_prtstr (len,"(null)");
    i = 0;
    while (str[i] != '\0')
    {
        ft_prtchar(str[i], len);
        i++;
    }
}
