/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:08:58 by mbjaghou          #+#    #+#             */
/*   Updated: 2021/12/05 17:09:00 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(unsigned long n, const char *base, int *cp)
{
	if (n >= 16)
		ft_pointer(n / 16, base, cp);
	ft_putchar(base[n % 16], cp);
}
