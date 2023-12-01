#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
    va_list args ;
    int printed_chars = 0;
    int i = 0;

