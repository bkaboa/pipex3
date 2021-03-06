/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:25:08 by czang             #+#    #+#             */
/*   Updated: 2022/03/20 02:17:41 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <errno.h>

/*
 *
 ******************************	structure	***
 */
typedef struct s_pipex
{
	pid_t id_process;
	pid_t id_process2;

	int pipe[2];

	int	infile;
	int	outfile;

	char **path;
	char **comd_arg;
	char *comd_path;
}t_pipex;

typedef struct s_arg
{
	short ac;
	char **av;
	char **env;
}t_arg;
/*
 *
 ******************************	define		***
 */
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_CMD "Command not found\n"
# define ERR_PIPE "error with pipe occured\n"
# define ERR_FORK "FORK: "
# define SPLIT_ERROR "split error in path\n"
# define ERR_PATH "path_error\n"
# define NO_ERRNO 0

/*
 *
 ******************************	typedef		***
 */



/*
 *
 ******************************	utils_pipex_functions	***
 */

char	**ft_split(char *s, char set);
/* small_include*/
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
bool	ft_strncmp(const char *s1, const char *s2, int len);
char	*ft_substr(const char *s1, char set);

/*
 *
 ******************************	free					***
 */

/* free_struct*/
void	free_struct_arg(t_arg *arg);
void	free_struct_pipex(t_pipex *pipex);
/* free_db_pointer */
void	free_db_pointer(void **pointer);

/*
 *
 ******************************	pipex_functions			***
 */

/* parse_function*/
bool	parse_pipex(t_pipex *pipex, t_arg argument);
/* fork_function */
int		ft_fork(t_pipex *pipex, t_arg arg);
/* command */
void	assign_comd(t_pipex *pipex, t_arg arg);
bool	find_comd(t_pipex *pipex, int i);

#endif
