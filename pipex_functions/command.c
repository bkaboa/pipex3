/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:49:36 by czang             #+#    #+#             */
/*   Updated: 2022/03/20 02:16:18 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static bool	command_not_found(int erno)
{
	perror(ERR_CMD);
	strerror(erno);
	return (false);
}

void	assign_comd(t_pipex *pipex, t_arg arg)
{
	int		i;

	i = 0;
	arg.ac -= 1;
	pipex->comd_arg = malloc(sizeof(char *) * (arg.ac));
	if (!pipex->comd_arg)
		return ;
	pipex->comd_arg[arg.ac - 1] = NULL;
	while (i < arg.ac - 1)
	{
		pipex->comd_arg[i] = ft_strdup(arg.av[i + 2]);
		if (pipex->comd_arg[i] == NULL)
			--i;
		++i;
	}
}

bool	find_comd(t_pipex *pipex, int i)
{
	char	**tmp_path;
	char	**tmp_comd;
	int		erno;

	tmp_comd = ft_split(pipex->comd_arg[i], ' ');
	tmp_path = pipex->path;
	if (pipex->comd_path)
		free(pipex->comd_path);
	while (*tmp_path)
	{
		pipex->comd_path = ft_strjoin(*tmp_path, "/");
		pipex->comd_path = ft_strjoin(pipex->comd_path, tmp_comd[0]);
		erno = access(pipex->comd_path, 0);
		if (erno == 0)
		{
			free_db_pointer((void **)tmp_comd);
			return(true);
		}
		free(pipex->comd_path);
		tmp_path++;
	}
	free_db_pointer((void **)tmp_comd);
	return (command_not_found(erno));
}
