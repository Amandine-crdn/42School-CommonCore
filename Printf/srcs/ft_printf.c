/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:45:08 by acerdan           #+#    #+#             */
/*   Updated: 2021/07/20 08:08:00 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	initialized_structure(t_sc *sc)
{
	sc->len = 0;
	sc->width = 0;
}

void	ft_choice_u(t_sc *sc, va_list arg)
{
	int	u;

	u = va_arg(arg, int);
	if (!u)
	{
		write(1, "0", 1);
		sc->len += 1;
	}
	else
	{
		ft_putnbr_u((unsigned int)u);
		sc->len = sc->len + ft_memlen((unsigned int)u, 10);
	}
}

char const	*ft_read_text(char const *format, t_sc *sc)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
		sc->width = next - format;
	else
		sc->width = ft_strlen(format);
	write(1, format, sc->width);
	sc->len = sc->len + sc->width;
	while (*format && *format != '%')
		++format;
	return (format);
}

char const	*ft_read_arg(char const *format, t_sc *sc, va_list arg)
{
	if (*format == 's')
		ft_choice_s(sc, arg);
	else if (*format == 'c')
		ft_choice_c(sc, arg);
	else if (*format == 'i' || *format == 'd')
		ft_choice_d_i(sc, arg);
	else if (*format == 'X' || *format == 'x')
		ft_choice_x(*format, sc, arg);
	else if (*format == 'p')
		ft_choice_p(sc, arg);
	else if (*format == 'u')
		ft_choice_u(sc, arg);
	else if (*format == '%')
		ft_choice_pourcent(sc);
	else
		return (NULL);
	format++;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	t_sc	sc;
	va_list	arg;

	initialized_structure(&sc);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_read_arg(format + 1, &sc, arg);
		else
			format = ft_read_text(format, &sc);
		if (!format)
		{
			va_end(arg);
			write(1, "(null)", 6);
			return (-1);
		}
	}
	va_end(arg);
	return ((int)sc.len);
}
