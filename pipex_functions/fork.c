/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:45:10 by czang             #+#    #+#             */
/*   Updated: 2022/03/20 02:11:51 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static int	child1(t_pipex *pipex, t_arg arg)
{
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	dup2(pipex->infile, 0);
	return (execve(pipex->comd_path, &pipex->comd_arg[0], arg.env));
}

static int	child2(t_pipex *pipex, t_arg arg)
{
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
	dup2(pipex->outfile, 1);
	return (execve(pipex->comd_path, &pipex->comd_arg[0], arg.env));
}

int	ft_fork(t_pipex *pipex, t_arg arg)
{
	int		i;

	i = 0;
	assign_comd(pipex, arg);
	if (find_comd(pipex, i) == true)
	{
		pipex->id_process = fork();
		if (pipex->id_process < 0)
			return (pipex->id_process);
		if (pipex->id_process == 0)
			return (child1(pipex, arg));
	}
	if (find_comd(pipex, i) == true)
	{
		pipex->id_process = fork();
		if (pipex->id_process < 0)
			return (pipex->id_process);
		if (pipex->id_process == 0)
		return (child2(pipex, arg));
	}
	return (0);
}
