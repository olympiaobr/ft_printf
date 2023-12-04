/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:26:03 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/04 19:26:10 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prtunsint(unsigned int nb, int *len)
{
	if (nb >= 10)
		ft_prtunsint(nb / 10, len);
	ft_prtchar(nb % 10 + '0', len);
}
