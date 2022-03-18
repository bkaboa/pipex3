/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:45:10 by czang             #+#    #+#             */
/*   Updated: 2022/03/19 00:50:53 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static int	childi1(t_piepx *pipex)
{
	
}

static int	childi1(t_piepx *pipex)
{
	
}

int	ft_fork(t_pipex *pipex, t_arg arg)
{
	int		i;

	i = 0;
	assign_comd(pipex, arg);
	if (find_comd(pipex, i) == true);
	{
		pipex->id_process = fork();
		if (pipex->id_process < 0)
			return (pipex->id_process);
		if (pipex->id_process == 0)
			return (child1(t_pipex));
	}
	if (find_comd(pipex, i) == true);
	{
		pipex->id_process = fork();
		if (pipex->id_process < 0)
			return (pipex->id_process);
		if (pipex->id_process == 0)
		return (child2(t_pipex));
	}
	return (0);
}
