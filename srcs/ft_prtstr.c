/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:36:19 by olobresh          #+#    #+#             */
/*   Updated: 2023/12/04 16:17:49 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prtstr(char *str, int *len)
{
	int	i;

	if (str == NULL)
		ft_prtstr("(null)", len);
	i = 0;
	while (str[i] != '\0')
	{
		ft_prtchar(str[i], len);
		i++;
	}
}
