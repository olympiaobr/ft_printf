/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:18:01 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/04 16:25:23 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prtint(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_prtchar('-', len);
		ft_prtchar('2', len);
		ft_prtint(147483648, len);
	}
	else if (nb < 0)
	{
		nb = -nb;
		ft_prtchar('-', len);
		ft_prtint(nb, len);
	}
	else if (nb > 9)
	{
		ft_prtint(nb / 10, len);
		ft_prtint(nb % 10, len);
	}
	else
	{
		ft_prtchar(nb + '0', len);
	}
}
