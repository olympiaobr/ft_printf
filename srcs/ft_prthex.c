#include "ft_printf.h"

static void ft_print_hex_char(unsigned long long hx, char *base)
{
    int index;

    index = hx % 16;
    write(1, &base[index], 1);
}

int ft_prthex(unsigned long long hx, char *base)
{
    unsigned long long temp_hx;
    int count;
    int printed_chars;

    temp_hx = hx;
    count = 0;
    printed_chars = 0;
    // Handle zero case
    if (hx == 0)
    {
        write(1, "0", 1);
        return 1;
    }
    // Count number of hex digits
    while (temp_hx != 0)
    {
        temp_hx /= 16;
        count++;
    }
    // Print each hex digit
    while (count-- > 0)
    {
        ft_print_hex_char(hx >> (count * 4), base);
        printed_chars++;
    }
    return (printed_chars);
}


OR

int ft_prthex(unsigned long long hx, char *base)
{
    int printed_chars;

    printed_chars = 0;
    if (hx >= 16)
    {
        printed_chars = ft_prthex(hx / 16, base);
    }
    write(1, &base[hx % 16], 1);
    return (printed_chars + 1);
}
//
