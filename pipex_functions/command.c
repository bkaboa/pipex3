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

static short	command_not_found(int erno, char *s)
{
	perror(s);
	strerror(erno);
	return (-1);
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

static short	spc_in_cmd(char *s)
{
	int		i;
	int		y;
	int		errno;

	errno = EINVAL;
	y = 0;
	i = 0;
	while (s[i])
		if (s[i++] == ' ')
			y++;
	if (y == 1)
		return (true);
	if (y > 1)
		return (command_not_found(errno, s));
	return (false);
}

bool	find_comd(t_pipex *pipex, int i)
{
	int		errno;
	char	*comd;
	size_t	y;

	y = 0;
	if (spc_in_cmd(pipex->comd_arg[i]) == -1)
		return (false);
	else if (spc_in_cmd(pipex->comd_arg[i]) == true)
		comd = ft_substr(pipex->comd_arg[i], ' ');
	else
		comd = ft_strdup(pipex->comd_arg[i]);
	while (pipex->path[y])
	{
		pipex->comd_path = ft_strjoin(pipex->path[y], comd);
		errno = access(pipex->comd_path, 0);
		if (errno >= 0)
		{
			return (true);
		}
		y++;
		free(pipex->comd_path);

	}
	return (command_not_found(errno, "command_not_found "));
}
