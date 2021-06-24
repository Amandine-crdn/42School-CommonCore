/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:41:39 by acerdan           #+#    #+#             */
/*   Updated: 2021/02/13 09:24:52 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[0] != '\0' && str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z' && str[i - 1] >= 123) ||
			(str[i] >= 'a' && str[i] <= 'z' && str[i - 1] <= 64) ||
			(str[i] >= 'a' && str[i] <= 'z' && str[i - 1] >= 91
				&& str[i - 1] <= 96))
			str[i] = str[i] - 32;
		if (str[i] >= 'A' && str[i] <= 'Z' &&
			str[i - 1] >= '0' && str[i - 1] <= '9')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
