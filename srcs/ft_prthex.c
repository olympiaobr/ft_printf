/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:21 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/04 16:28:55 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prthex(unsigned long long hx, char *b, int *prt_chrs)
{
	if (hx >= 16)
	{
		*prt_chrs = ft_prthex(hx / 16, b, prt_chrs);
	}
	write(1, &b[hx % 16], 1);
	(*prt_chrs)++;
	return (1);
}
