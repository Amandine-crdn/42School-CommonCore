/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:45:00 by acerdan           #+#    #+#             */
/*   Updated: 2021/07/20 15:19:14 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>

void	ft_choice_s(t_sc *sc, va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		sc->len = sc->len + 6;
	}
	else
	{
		ft_putstr(s);
		sc->len = sc->len + ft_strlen(s);
	}
}

void	ft_choice_c(t_sc *sc, va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	ft_putchar(c);
	sc->len = sc->len + 1;
}

void	ft_choice_d_i(t_sc *sc, va_list arg)
{
	int	i;

	i = va_arg(arg, int);
	ft_putnbr(i);
	sc->len = sc->len + ft_intlen(i);
}

void	ft_choice_p(t_sc *sc, va_list arg)
{
	void	*p;

	p = va_arg(arg, void *);
	if (!p)
	{
		write(1, "0x0", 3);
		sc->len += 3;
	}
	else
	{
		write(1, "0x", 2);
		sc->len += 2;
		ft_print_adress((unsigned long)p);
		sc->len = sc->len + ft_memlen((unsigned long)p, 16);
	}
}

void	ft_choice_x(char c, t_sc *sc, va_list arg)
{
	unsigned int	x;

	x = va_arg(arg, unsigned int);
	ft_print_hexa_x((unsigned long)x, c);
	if (x == 0 || x == (int)LONG_MIN)
		sc->len = sc->len + ft_memlen((unsigned long)x, 16) + 1;
	else
		sc->len = sc->len + ft_memlen((unsigned long)x, 16);
}
