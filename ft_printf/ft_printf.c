/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:09:04 by mbjaghou          #+#    #+#             */
/*   Updated: 2021/12/08 15:25:36 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_printf(const char *tmp, va_list av, int i, int *cp)
{
	i++;
	if (tmp[i] == 'c')
		ft_putchar(va_arg(av, int), cp);
	if (tmp[i] == 's')
		ft_putstr(va_arg(av, char *), cp);
	if (tmp[i] == 'd' || tmp[i] == 'i')
		ft_putnbr(va_arg(av, int), cp);
	if (tmp[i] == '%')
		ft_putchar('%', cp);
	if (tmp[i] == 'u')
		ft_putnbr_unsigned(va_arg(av, unsigned int), cp);
	if (tmp[i] == 'x')
		ft_hexa(va_arg(av, unsigned long), "0123456789abcdef", cp);
	if (tmp[i] == 'X')
		ft_hexa(va_arg(av, unsigned long), "0123456789ABCDEF", cp);
	if (tmp[i] == 'p')
	{
		ft_putstr("0x", cp);
		ft_pointer(va_arg(av, unsigned long), "0123456789abcdef", cp);
	}
}

int	ft_printf(const char *tmp, ...)
{
	int		i;
	int		cp;
	va_list	av;

	i = 0;
	cp = 0;
	va_start(av, tmp);
	while (tmp[i])
	{
		if (tmp[i] != '%')
			ft_putchar(tmp[i], &cp);
		else
		{
			my_printf(tmp, av, i, &cp);
			i++;
		}
		i++;
	}
	va_end(av);
	return (cp);
}
