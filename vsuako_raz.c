/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsuako_raz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:44:29 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:27:44 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s && *s[i])
		free(s[i]);
	free(s);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*new_strjoin(char *s1, char *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*res;

	l1 = 0;
	l2 = 0;
	while (s1 && s1[l1])
		l1++;
	while (s2 && s2[l2])
		l2++;
	res = (char *)malloc(l1 + l2 + 1);
	if (!res)
		return (ft_free(&s1));
	i = -1;
	while (++i < l1)
		res[i] = s1[i];
	i = -1;
	while (++i < l2)
		res[i + l1] = s2[i];
	res[l1 + l2] = 0;
	(ft_free(&s1) || ft_free(&s2));
	return (res);
}

int	count_coll(t_game *game)
{
	char	*str;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (game->map[i])
	{
		str = game->map[i];
		while (*str)
		{
			if (*str == 'C')
				ret++;
			str++;
		}
		i++;
	}
	return (ret);
}
