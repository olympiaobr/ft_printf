#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "./libft/includes/libftprintf.h"

void	ft_pr_char(char character, int *len);
void	ft_pr_str(char *str, int *len);
void	ft_pr_int(int number, int *len);
void	ft_pr_unsigned(unsigned int nbr, int *len);
void	ft_pr_hex(unsigned int num, int *len, char format);
void	ft_pr_ptr(size_t ptr, int *len);

int	ft_printf(const char *str, ...);

#endif
