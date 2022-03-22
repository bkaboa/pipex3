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


SRCS	=				\
	$(PPATH)pipex.c		\
	$(PPATH)free.c		\
	$(PPATH)fork.c		\
	$(PPATH)command.c	\
	$(PPATH)parse.c		\
	$(UPATH)split.c		\
	$(UPATH)small_utils.c
