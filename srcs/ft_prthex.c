/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:21 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/05 11:40:55 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prthex(unsigned long long hx, char f, int *prt_chrs)
{
	char	*hx_b;
	int		i;

	if (f == 'x')
		hx_b = "0123456789abcdef";
	else
		hx_b = "0123456789ABCDEF";
	if (hx >= 16)
	{
		ft_prthex(hx / 16, f, prt_chrs);
	}
	i = hx % 16;
	write(1, &hx_b[i], 1);
	(*prt_chrs)++;
	return (*prt_chrs);
}
