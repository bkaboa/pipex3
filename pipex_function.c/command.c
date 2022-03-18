/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:49:36 by czang             #+#    #+#             */
/*   Updated: 2022/03/18 17:27:13 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static bool	command_not_found(int errno)
{
	perror(ERR_CMD);
	strerror(erno);
	return (false);
}

static char	*assign_comd(t_arg arg, int i)
{
	if (open(arg.av[i], O_RDONLY) < 0)
	{
		free_struct_arg(arg);
		return (arg.av[i]);
	}
	free_struct_arg(arg);
}

