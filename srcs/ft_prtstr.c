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

int ft_prtstr(char *str, int *l)
{
    int i;

    i = 0;
    if (!str)
    {
        str = "(null)";
    }
    while (str[i] != '\0') {
        ft_prtchar(str[i], l);
        i++;
    }
    return (l);
}
