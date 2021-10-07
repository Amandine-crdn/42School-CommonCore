/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:44:45 by acerdan           #+#    #+#             */
/*   Updated: 2021/07/20 14:50:44 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_sc
{
	size_t	len;
	size_t	width;
}				t_sc;
void	ft_choice_pourcent(t_sc *sc);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putnbr(int nb);
void	ft_print_hexa_x(unsigned long nbr, char c);
void	ft_print_adress(unsigned long nbr);
void	ft_putnbr_u(unsigned int nb);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_choice_s(t_sc *sc, va_list arg);
void	ft_choice_c(t_sc *sc, va_list arg);
void	ft_choice_d_i(t_sc *sc, va_list arg);
void	ft_choice_p(t_sc *sc, va_list arg);
void	ft_choice_x(char c, t_sc *sc, va_list arg);
int		ft_memlen(unsigned long addr, unsigned int base);
int		ft_intlen(int nb);
int		ft_printf(const char *format, ...);

#endif
