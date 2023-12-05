/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:52:30 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/04 17:06:38 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_case(char f, va_list args, int *char_sum)
{
	if (f == 'c')
		(ft_prtchar(va_arg(args, int), char_sum));
	else if (f == 's')
		(ft_prtstr(va_arg(args, char*), char_sum));
	else if (f == 'p')
		(ft_prtptr(va_arg(args, void *), char_sum));
	else if (f == 'd' || f == 'i')
		(ft_prtint(va_arg(args, unsigned int), char_sum));
	else if (f == 'u')
		(ft_prtunsint(va_arg(args, unsigned int), char_sum));
	else if (f == 'x' || f == 'X')
		(ft_prthex(va_arg(args, unsigned int), f, char_sum));
	else if (f == '%')
	{
		write(1, "%", 1);
		(*char_sum)++;
	}
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		char_sum;
	int		i;

	va_start(args, f);
	char_sum = 0;
	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			conv_case(f[i], args, &char_sum);
		}
		else
		{
			write(1, &f[i], 1);
			char_sum++;
		}
		i++;
	}
	va_end(args);
	return (char_sum);
}
/*
*/
