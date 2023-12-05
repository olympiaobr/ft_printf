/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:29:03 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/05 11:43:52 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prtptr(void *ptr, int *len)
{
	unsigned long long	ptr_a;

	if (!ptr)
	{
		return (ft_prtstr("(nil)", len));
	}
	ptr_a = (unsigned long long)ptr;
	ft_prtstr("0x", len);
	return (ft_prthex(ptr_a, 'x', len)); 
}
