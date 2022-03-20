/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:35:49 by czang             #+#    #+#             */
/*   Updated: 2022/03/20 01:51:58 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	free_struct_arg(t_arg *arg)
{
	free_db_pointer((void **)arg->av);
	free_db_pointer((void **)arg->env);
}

void	free_struct_pipex(t_pipex *pipex)
{
	free_db_pointer((void **)pipex->path);
	free_db_pointer((void **)pipex->comd_arg);
	free(comd_path);
}

void	free_db_pointer(void **pointer)
{
	void	**tmp;

	tmp = pointer;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(pointer);
}
