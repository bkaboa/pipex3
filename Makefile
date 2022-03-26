# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 00:12:04 by czang             #+#    #+#              #
#    Updated: 2022/03/22 18:43:46 by czang            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

include			config/srcs.mk

EXEC	=		pipex

IPATH	=		Includes
OPATH	=		.obj

FFLAGS	=		-fsanitize=address -g3
CFLAGS	=		-Werror -Wextra -Wall
IFLAGS	=		-I $(IPATH)
OBJS	=		$(addprefix $(OPATH)/, $(SRCS:.c=.o))

INC		=		$(addprefix $(IPATH)/, pipex.h)
	
all:			$(EXEC)

$(EXEC):		$(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

re:				fclean all

$(OPATH)/%.o:	%.c $(INC) config/srcs.mk Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

memoire:		CFLAGS += $(FFLAGS)
memoire:		re

clean:
	@$(RM) $(OBJS)

fclean:			clean
	@$(RM) $(EXEC)
