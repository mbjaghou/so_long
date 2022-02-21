/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:09:24 by mbjaghou          #+#    #+#             */
/*   Updated: 2021/12/05 17:09:26 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *cp)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*cp = *cp + 11;
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-', cp);
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar(n + '0', cp);
	}
	else
	{
		ft_putnbr(n / 10, cp);
		ft_putchar(n % 10 + 48, cp);
	}
}
