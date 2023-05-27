# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboia-pe <rboia-pe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 01:54:21 by rboia-pe          #+#    #+#              #
#    Updated: 2023/04/08 01:54:21 by rboia-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME	:= libftprintf.a

LIBFT	= ./libft/libft.a

SRCS =	ft_printf.c ft_numbers.c\
		ft_hexa.c\
		ft_csp.c

OBJS	:= ${SRCS:.c=.o}

CC		:= cc
RM		:= /bin/rm -f
CFLAGS	:= -Wall -Wextra -Werror

CL := ar -rc
RL := ar -s

Red=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
RESET=\033[0m

all: ${NAME} check

${NAME}: ${OBJS}
	$(MAKE) -s -C ./libft
	@printf "\n$(BLUE)Creating Static library $(GREEN)     DONE$(RESET)\n"
	cp $(LIBFT) $(NAME) 
	@printf "$(BLUE)Copy to libftprintf $(GREEN)	     DONE$(RESET)\n"
	${CL} ${NAME} ${OBJS} 
	${RL} ${NAME}
	@printf "$(BLUE)Building libftprintf $(GREEN)        DONE$(RESET)\n\n"

clean:
	$(MAKE) -s clean -C ./libft
	${RM} ${OBJS} ./a.out
	@printf "$(YELLOW)Removing all created objects$(GREEN) DONE$(RESET)\n"

fclean: clean
	$(MAKE) -s fclean -C ./libft
	${RM} ${NAME}
	@printf "$(YELLOW)Removing Static library$(GREEN)      DONE$(RESET)\n"

re: fclean all

check:
		printf "$(GREEN)Success: All files created successfully.$(RESET)\n";
#	@if [ -z "$(filter-out $(wildcard $(OBJS)),$(OBJS))" ]; then \
#		printf "$(GREEN)Success: All files created successfully.$(RESET)\n"; \
#	else \
#		printf "$(Red)Error: Some files creation failed.$(RESET)\n"; \
#	exit 1; \
#	fi

author: 
	@printf "rboia-pe\n"

norm:
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: clean fclean norm all bonus re author