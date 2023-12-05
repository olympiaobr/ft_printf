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

int ft_prthex(unsigned long long hx, char f, int *prt_chrs)
{
    char *hx_b;
    char c;
    int i;

    hx_b = "0123456789abcdef";
    if (hx >= 16)
    {
        *prt_chrs += ft_prthex(hx / 16, f, prt_chrs);
    }
    i = hx % 16;
    c = hx_b[i];
    if (f == 'X' && c >= 'a' && c <= 'f')
    {
        c -= 32;
    }
    write(1, &c, 1);
    (*prt_chrs)++;
    return (1);
}
