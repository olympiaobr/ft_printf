#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

void	ft_prtchar(char character, int *len);
void	ft_prtstr(char *str, int *len);
void	ft_prtint(int nb, int *len);
void	ft_prtunsint(unsigned int nbr, int *len);
int		ft_prthex(unsigned long long hx, char *base);
void	ft_prtptr(void *ptr, int *len);

int		ft_printf(const char *f, ...);

#endif
