/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:09:10 by mbjaghou          #+#    #+#             */
/*   Updated: 2021/12/05 17:09:11 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

void	ft_putchar(char c, int *cp);
void	ft_putnbr(int n, int *cp);
int		ft_printf(const char *tmp, ...);
void	ft_putnbr_unsigned(unsigned int n, int *cp);
void	ft_hexa(unsigned int n, const char *base, int *cp);
void	ft_putstr(char *str, int *cp);
void	ft_pointer(unsigned long n, const char *base, int *cp);

#endif