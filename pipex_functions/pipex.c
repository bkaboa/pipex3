/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:40:28 by czang             #+#    #+#             */
/*   Updated: 2022/03/20 01:54:43 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg argument;
	t_pipex pipex;

	argc -= 1;
	argument.ac = argc;
	argument.av = argv;
	argument.env = envp;
	if (parse_pipex(&pipex, argument) == false)
		return (1);
	free_struct_pipex(&pipex);
	return (0);
}
