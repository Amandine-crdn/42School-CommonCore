/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:39:24 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_errormalloc_return_null(char *s)
{
	printf("cd: error malloc\n");
	if (s)
		free(s);
	return (NULL);
}

char	**ft_free_str_null_tab(int *s, char *s2, char **s3)
{
	int	i;

	i = 0;
	if (s)
		free(s);
	if (s2)
		free(s2);
	if (s3)
	{
		while (s3[i])
		{
			free(s3[i]);
			i++;
		}
		free(s3);
	}
	return (NULL);
}
