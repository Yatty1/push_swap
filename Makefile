# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 21:25:07 by syamada           #+#    #+#              #
#    Updated: 2018/08/25 19:09:40 by syamada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
DEBUG		:= -g
SANITIZER	:= -fsanitize=address

LIB			:= libft.a
LIBDIR		:= libft

CHECKER		:= checker
SWAP		:= push_swap

SRCDIR		:= srcs
INCDIR		:= includes
OPSDIR		:= $(addprefix $(SRCDIR)/, ops)

CHECKERSRC	:= $(addprefix $(SRCDIR)/, checker.c)
SWAPSRC		:= $(addprefix $(SRCDIR)/, push_swap.c)
OPSRCS		:= $(addprefix $(OPSDIR)/, swap_funcs.c push_funcs.c rotate_funcs.c \
					rev_rotate_funcs.c)

OTHERSRCS	:= $(addprefix $(SRCDIR)/, create_stack.c stack_funcs.c stack_helpers.c \
					checker_helpers.c ft_errorexit.c check_option.c oplist_funcs.c \
					sort_helpers.c optimization.c oplist_helpers.c \
					bubble_sort.c insertion_sort.c sort.c)

#colors
COM_COLOR	:= \033[0;34m
OK_COLOR	:= \033[0;32m
EXEC_COLOR	:= \033[1;32m
DEBUG_COLOR	:= \033[0;33m
NO_COLOR	:= \033[m

.PHONY: all
all: $(CHECKER) $(SWAP)

$(CHECKER): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(CHECKERSRC) $(OPSRCS) $(OTHERSRCS) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

$(SWAP): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(SWAPSRC) $(OPSRCS) $(OTHERSRCS) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

$(LIBDIR)/$(LIB):
	@make -C $(LIBDIR)

.PHONY: clean
clean:
	@make -C $(LIBDIR) clean

.PHONY: fclean
fclean:
	@make -C $(LIBDIR) fclean
	@printf "%b" "$(NO_COLOR)Removing $(CHECKER) $(SWAP)...\n"
	@rm -f $(CHECKER)
	@rm -f $(SWAP)
	@printf "%b" "$(OK_COLOR)[OK]: $(NO_COLOR)$(CHECKER), $(SWAP) were successfully removed\n"

.PHONY: re
re: fclean all

.PHONY: debug
debug:
	@rm -f d$(CHECKER)
	@rm -f d$(SWAP)
	@make d$(CHECKER)
	@make d$(SWAP)

d$(CHECKER): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(DEBUG_COLOR)[DEBUG MODE] $(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(DEBUG) $(CHECKERSRC) $(OPSRCS) $(OTHERSRCS) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

d$(SWAP): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(DEBUG_COLOR)[DEBUG MODE] $(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(DEBUG) $(SWAPSRC) $(OPSRCS) $(OTHERSRCS) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

.PHONY: cleandebug
cleandebug:
	@rm -rf d$(CHECKER).dSYM
	@rm -rf d$(SWAP).dSYM
	@rm -f d$(CHECKER)
	@rm -f d$(SWAP)

.PHONY: qc
qc:
	@printf "%b" "Quick recompile for $(CHECKER)\n"
	@rm -f $(CHECKER)
	@make $(CHECKER)

.PHONY: qs
qs:
	@printf "%b" "Quick recompile for $(SWAP)\n"
	@rm -f $(SWAP)
	@make $(SWAP)

.PHONY: rec
rec: fclean $(CHECKER)

.PHONY: res
res: fclean $(SWAP)
