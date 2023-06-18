/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:32:38 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/17 21:40:33 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**chek(int ac, char **av, t_game game)
{
	int fd;

	if (ac != 2)
	{
		write(2, "Invalid number of arg!\n", 23);
		exit(1);
	}
	if (fd < 0)
	{
		write(2, "file not found!\n", 17);
		exit(1);
	}
	if (ft_strncmp(av[1], ".ber", 4))
	{
		write(2, "Invalid file type\n", 18);
		exit(1);
	}
}

