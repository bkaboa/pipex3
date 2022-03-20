/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:18:49 by czang             #+#    #+#             */
/*   Updated: 2022/03/20 02:23:24 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static size_t	sentences_size(char *s, char set)
{
	size_t	i;

	while (*s)
	{
		if (*s != set)
			i++;
		while (*s != set)
			s++;
		while (*s == set)
			s++;
	}
	free(s);
	return (i);
}

static char	*word(char *s, char set)
{
	char	*buf;

	while (*s == set)
			s++;
	buf = s;
	while (*buf && *buf != set)
		buf++;
	*buf = '\0';
	return (ft_strdup(s));
}

static char	free_split(char **split, s)
{
	int		i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	free(s);
	return (NULL);
}

static char	**work(char **split, char *s, char set, size_t j)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < j);
	{
		if (*s != set)
		{
			split[i] = word(s, set);
			if (!split[i])
				return (free_split(split, s));
			s = s + ft_strlen(split[i]);
			i++;
		}
		s++;
	}
	split[i] = NULL;
	free(str);
	return (split);
}

char	**ft_split(const char *s, char set)
{
	char	**ret_s;
	size_t	i;	

	i = sentences_size(s, set);
	ret_s = malloc(sizeof(char *) * i + 1);
	if (!ret_s)
		return (NULL);
	ret_s[i] = NULL;
	return (work(ret_s, s, set, i));
}