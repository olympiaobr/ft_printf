#include "ft_printf.h"

int conv_case(char f, va_list args, int *total_printed_chars)
{
    if (f == 'c')
        return (ft_prtchar(va_arg(args, int), total_printed_chars));
    else if (f == 's')
        return (ft_prtstr(va_arg(args, char*), total_printed_chars));
    else if (f == 'p')
        return (ft_prtptr(va_arg(args, void*), total_printed_chars));
    else if (f == 'd' || f == 'i')
        return (ft_prtint(va_arg(args, int), total_printed_chars));
    else if (f == 'u')
        return (ft_prtunsint(va_arg(args, unsigned int), total_printed_chars));
    else if (f == 'x' || f == 'X')
        return (ft_prthex(va_arg(args, unsigned int), total_printed_chars, f));
    else if (f == '%')
    {
        write(1, "%", 1);
        return (1);
    }
    return (0);
}

int ft_printf(const char *f, ...)
{
    va_list args;
    int total_printed_chars;
    int i;

    va_start(args, f);
    total_printed_chars = 0;
    i = 0;
    while (f[i])
    {
        if (f[i] == '%')
            total_printed_chars += conv_case(f[++i], args, &total_printed_chars);
        else
        {
            write(1, &f[i], 1);
            total_printed_chars++;
        }
        i++;
    }
    va_end(args);
    return (total_printed_chars);
}

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ret_ft_printf, ret_printf;
    unsigned int max_unsigned_int = UINT_MAX;
    int max_int = INT_MAX;
    int min_int = INT_MIN;
    long long large_hex = 0x7FFFFFFFFFFFFFFFLL;
    char *empty_string = "";
    char *null_string = NULL;
    void *null_pointer = NULL;
    int zero = 0;
    int negative_number = -12345;
    unsigned long long large_unsigned = ULLONG_MAX;
    void *invalid_ptr = (void *)0xdeadbeef; // Arbitrary invalid address
    char null_char = '\0';

    // Include nested ft_printf call for complex string testing
    ret_ft_printf = ft_printf("\nNested ft_printf test: %d\n", ft_printf("Testing: %c %s %d %i %u %p %x %X %%\n", 'A', "Hello world", 42, -42, max_unsigned_int, &ret_ft_printf, 255, 255));
    ret_printf = printf("\nNested printf test: %d\n", printf("Testing: %c %s %d %i %u %p %x %X %%\n", 'A', "Hello world", 42, -42, max_unsigned_int, &ret_printf, 255, 255));
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with maximum and minimum integer values
    ret_ft_printf = ft_printf("Max int ft_printf: %d\n", max_int);
    ret_printf = printf("Max int printf: %d\n", max_int);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    ret_ft_printf = ft_printf("Min int ft_printf: %d\n", min_int);
    ret_printf = printf("Min int printf: %d\n", min_int);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with a large hexadecimal value
    ret_ft_printf = ft_printf("Large Hex ft_printf: %llx\n", large_hex);
    ret_printf = printf("Large Hex printf: %llx\n", large_hex);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with percent sign
    ret_ft_printf = ft_printf("Percent ft_printf: %%\n");
    ret_printf = printf("Percent printf: %%\n");
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with empty string
    ret_ft_printf = ft_printf("Empty string ft_printf: '%s'\n", empty_string);
    ret_printf = printf("Empty string printf: '%s'\n", empty_string);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with NULL string
    ret_ft_printf = ft_printf("NULL string ft_printf: '%s'\n", null_string);
    ret_printf = printf("NULL string printf: '%s'\n", null_string);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with zero and negative numbers
    ret_ft_printf = ft_printf("Zero ft_printf: %d, Negative ft_printf: %d\n", zero, negative_number);
    ret_printf = printf("Zero printf: %d, Negative printf: %d\n", zero, negative_number);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with NULL pointer
    ret_ft_printf = ft_printf("NULL pointer ft_printf: %p\n", null_pointer);
    ret_printf = printf("NULL pointer printf: %p\n", null_pointer);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with large unsigned number
    ret_ft_printf = ft_printf("Large unsigned ft_printf: %llu\n", large_unsigned);
    ret_printf = printf("Large unsigned printf: %llu\n", large_unsigned);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test with invalid pointer
    ret_ft_printf = ft_printf("Invalid pointer ft_printf: %p\n", invalid_ptr);
    ret_printf = printf("Invalid pointer printf: %p\n", invalid_ptr);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    // Test printing the null character
    ret_ft_printf = ft_printf("Null char ft_printf: '%c'\n", null_char);
    ret_printf = printf("Null char printf: '%c'\n", null_char);
    printf("\nft_printf returned: %d\nprintf returned: %d\n\n", ret_ft_printf, ret_printf);

    char *long_string = malloc(10000); // Dynamically allocate a long string
    memset(long_string, 'A', 9999);
    long_string[9999] = '\0';
    ret_ft_printf = ft_printf("Long string test: %s\n", long_string);
    ret_printf = printf("Long string test: %s\n", long_string);

    // Validate return values
    if (ret_ft_printf != ret_printf)
    {
        fprintf(stderr, "Mismatch for long string: ft_printf (%d) vs printf (%d)\n", ret_ft_printf, ret_printf);
    }

    free(long_string);

    // Test with malformed format specifier
    ret_ft_printf = ft_printf("Malformed specifier test: %z\n");
    ret_printf = printf("Malformed specifier test: %z\n");

    // Validate return values
    if (ret_ft_printf != ret_printf)
    {
        fprintf(stderr, "Mismatch for malformed specifier: ft_printf (%d) vs printf (%d)\n", ret_ft_printf, ret_printf);
    }

    return 0;
}

