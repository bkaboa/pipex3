# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 01:15:40 by czang             #+#    #+#              #
#    Updated: 2022/03/20 01:33:01 by czang            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

PPATH	=		pipex_functions/
UPATH	=		utils_functions/


SRCS	=								\
	$(addprefix $(PPATH), pipex.c)		\
	$(addprefix $(PPATH), fork.c)		\
	$(addprefix $(PPATH), command.c)	\
	$(addprefix $(PPATH), parse.c)		\
	$(addprefix $(UPATH), split.c)		\
	$(addprefix $(UPATH), small_utils.c)
