/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:29:03 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/04 16:42:04 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prtptr(void *ptr, int *len)
{
	unsigned long long	a;

	if (!ptr)
	{
		ft_prtstr("(nil)", len);
		return ;
	}
	a = (unsigned long long)ptr;
	*len += ft_prthex(a, "0123456789abcdef", len);
}
