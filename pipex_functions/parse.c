/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:00:24 by czang             #+#    #+#             */
/*   Updated: 2022/03/22 18:58:01 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static bool	print_error(char *err, int erno)
{
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
	size_t	i;

	i = 0;
	tmp = arg.env;
	while (ft_strncmp(*tmp, "PATH", 4) == false)
		tmp++;
	pipex->path = ft_split(*tmp, ':');
	if (!pipex->path)
		return (false);
	while (pipex->path[i])
	{
		pipex->path[i] = ft_strjoin(pipex->path[i], "/");
		i++;
	}
	return (true);
}

static void	close_and_wait(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
	close(pipex->outfile);
	waitpid(pipex->id_process2, NULL, 0);
}	

bool	parse_pipex(t_pipex *pipex, t_arg arg)
{
	int		erno;

	if (arg.ac < 3 || arg.ac > 4)
		return (print_error(ERR_INPUT, NO_ERRNO));
	pipex->infile = open((arg.av)[1], O_RDONLY);
	if (pipex->infile < 0)
		return (print_error((arg.av)[0], pipex->infile));
	pipex->outfile=open((arg.av)[arg.ac], O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (pipex->outfile < 0)
		return (print_error((arg.av)[arg.ac], pipex->outfile));
	erno = pipe(pipex->pipe);
	if (erno < 0)
		return (print_error(ERR_PIPE, erno));
	if (find_path(pipex, arg) == false)
		return (print_error(ERR_PATH, NO_ERRNO));
	if (ft_fork(pipex, arg) == false)
		return (print_error(ERR_FORK, pipex->id_process));
	close_and_wait(pipex);
	return (true);
}	
