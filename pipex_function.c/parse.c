/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:00:24 by czang             #+#    #+#             */
/*   Updated: 2022/03/18 15:03:13 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static bool	print_error(char *err, int erno, t_arg *arg)
{
	free_struct_arg(arg);
	if (erno)
	{
		perror(err);
		strerror(erno);
	}
	else
		write(2, err, ft_strlen(err));
	return (false);
}

static bool	find_path(t_pipex *pipex, t_arg arg)
{
	char	**tmp;

	tmp = arg.envp;
	while (ft_strncmp(*tmp, "PATH", 4) == false)
		tmp++;
	pipex->path = ft_split(*tmp, ':');
	free_struct_arg(arg);
	if (!pipex->path)
		return (false);
	return (true);
}

bool	parse_pipex(t_pipex *pipex, t_arg arg)
{
	int		erno;

	if (argument.argc < 3)
		return (print_error(ERR_INPUT, NO_ERRNO, &arg));
	pipex->infile = open((arg.av)[1], O_RDONLY);
	if (pipex->infile < 0)
		return (print_error((arg.av)[0], pipex->infile, &arg));
	pipex.outfile->open((arg.av)[arg.ac], O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (pipex->outfile < 0)
		return (print_error((arg.av)[arg.ac], pipex->outfile, &arg));
	erno = pipe(pipex->pipe);
	if (erno < 0)
		return (print_error(ERR_PIPE, erno, &arg));
	if (find_path(pipex, arg) == false)
		return (print_error(ERR_PATH, NO_ERRNO, &arg));
	if (ft_fork(pipex, arg) == false)
		return (print_error(ERR_FORK, pipex->id_process, &arg));
	return (true);
}	
