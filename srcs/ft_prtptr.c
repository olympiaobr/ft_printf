#include "libftprintf.h"

/* ooold void ft_prtptr(void *ptr, int *len)
{
    unsigned long long a;

    ft_prtstr("0x", len);

    if (ptr == NULL)
    {
        ft_prtstr("0", len);
    }
    else
    {
        a = (unsigned long long)ptr;
        *len += ft_prthex(a, "0123456789abcdef");
    }
}
*/
//better one?
void ft_prtptr(void *ptr, int *len)
{
    unsigned long long a;

    if (!ptr)
    {
        ft_prtstr("(nil)", len);
        return;
    }
    ft_prtstr("0x", len);
    a = (unsigned long long)ptr;
    *len += ft_prthex(a, "0123456789abcdef");
}
