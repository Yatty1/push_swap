# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 21:25:07 by syamada           #+#    #+#              #
#    Updated: 2018/08/09 15:23:29 by syamada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
DEBUG		:= -g
SANITIZER	:= -fsanitizer=address

CHECKER		:= checker
SWAP		:= push_swap

CHECKERSRC	:= checker.c
SWAPSRC		:= push_swap.c
OTHERSRCS	:= create_stack.c stack_funcs.c stack_helpers.c checker_helpers.c \
				swap_funcs.c push_funcs.c rotate_funcs.c rev_rotate_funcs.c \
				ft_errorexit.c

LIBCDIR		:= libc_funcs
ADDDIR		:= add_funcs
LISTDIR		:= list_funcs
EXTRADIR	:= extra_funcs
NTOADIR		:= ntoa_funcs
PRINTFDIR	:= printf_funcs

LIBCS	:= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
			ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c

ADDS	:= ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
			ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_puterr.c ft_putstrerr.c

LISTS	:= ft_samplelist.c ft_printlist.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_lstpush.c

EXTRAS	:= ft_strinit.c	ft_strrev.c ft_wordcount.c ft_strjoin_with.c get_next_line.c ft_strndup.c \
	ft_charstr.c ft_strprepend.c ft_strappend.c  ft_atol.c ft_strjoinfree.c ft_strjoinfree_with.c\

NTOAS	:= ft_itoa_base.c ft_ltoa_base.c ft_lltoa_base.c ft_uitoa_base.c ft_ultoa_base.c ft_ulltoa_base.c \
			ft_ltoa.c ft_lltoa.c ft_imaxtoa.c ft_uimaxtoa_base.c ft_sizetoa_base.c

PRINTF	:= ft_printf.c \
			format_c.c format_d.c format_i.c format_o.c format_p.c format_s.c format_u.c format_x.c format_percent.c\
			is.c parsers.c width_prec_fill.c flag_checker.c flag_converter.c \
			ls_handler.c lc_handler.c wp_helper.c ft_helper.c

LIBC_D	:= $(addprefix $(LIBCDIR)/, $(LIBCS))
ADD_D	:= $(addprefix $(ADDDIR)/, $(ADDS))
LIST_D	:= $(addprefix $(LISTDIR)/, $(LISTS))
EXTRA_D	:= $(addprefix $(EXTRADIR)/, $(EXTRAS))
NTOA_D	:= $(addprefix $(NTOADIR)/, $(NTOAS))
PRINT_D	:= $(addprefix $(PRINTFDIR)/, $(PRINTF))

ALL		:= $(LIBC_D) $(ADD_D) $(LIST_D) $(EXTRA_D) $(NTOA_D) $(PRINT_D)

LIB			:= libft.a
LIBDIR		:= libft
LIBSRCDIR	:= $(addprefix $(LIBDIR)/, srcs)
LIBOBJDIR	:= $(addprefix $(LIBDIR)/, obj)
LIBINCDIR	:= $(addprefix $(LIBDIR)/, includes)
LIBSRCS		:= $(addprefix $(LIBSRCDIR)/, $(ALL))
LIBOBJS		:= $(addprefix $(LIBOBJDIR)/, $(patsubst %.c, %.o, $(ALL)))

#colors
COM_COLOR	:= \033[0;34m
CR_COLOR	:= \033[1;34m
SRC_COLOR	:= \033[0;33m
OK_COLOR	:= \033[0;32m
LIB_COLOR	:= \033[1;32m
ERROR_COLOR	:= \033[0;31m
WARN_COLOR	:= \033[0;33m
NO_COLOR	:= \033[m

# prompt
OK_STR		:= "[OK]"
ERROR_STR	:= "[ERROR]"
WARN_STR 	:= "[WARNING]"
COM_STR   	:= "Compiling"

.PHONY: all
all: $(CHECKER) $(SWAP)

$(CHECKER): $(LIB)
	$(CC) -o $@ $(OTHERSRCS) $(CFLAG) $(CHECKERSRC) $(LIB) -I.

$(SWAP): $(LIB)
	$(CC) -o $@ $(OTHERSRCS) $(CFLAG) $(SWAPSRC) $(LIB) -I.

$(LIB): $(LIBOBJS)
	@printf "%b" "$(NO_COLOR)Creating $@...\n"
	@ar rcs $@ $^
	@ranlib $@
	@printf "%b" "$(CR_COLOR)Created archive: $(LIB_COLOR)$@\n"

$(LIBOBJDIR)/%.o: $(LIBSRCDIR)/%.c | $(LIBOBJDIR)
	@$(CC) -c $(CFLAGS) -I$(LIBINCDIR) $< -o $@

$(LIBOBJDIR):
	@printf "$(NO_COLOR)Creating obj/ directory...\n"
	@mkdir $(LIBOBJDIR)
	@mkdir $(addprefix $(LIBOBJDIR)/, $(LIBCDIR))
	@mkdir $(addprefix $(LIBOBJDIR)/, $(ADDDIR))
	@mkdir $(addprefix $(LIBOBJDIR)/, $(LISTDIR))
	@mkdir $(addprefix $(LIBOBJDIR)/, $(EXTRADIR))
	@mkdir $(addprefix $(LIBOBJDIR)/, $(NTOADIR))
	@mkdir $(addprefix $(LIBOBJDIR)/, $(PRINTFDIR))
	@printf "$(OK_COLOR)$(COM_STR)...\n"

.PHONY: clean
clean:
	@printf "%b" "$(NO_COLOR)Removing .o files...\n"
	@rm -rf $(LIBOBJDIR)
	@printf "%b" "$(OK_COLOR)$(OK_STR): $(NO_COLOR).o files were successfully removed\n"

.PHONY: fclean
fclean: clean
	@printf "%b" "$(NO_COLOR)Removing $(NAME)...\n"
	@rm -f $(CHECKER)
	@rm -f $(SWAP)
	@rm -f $(LIB)
	@printf "%b" "$(OK_COLOR)$(OK_STR): $(NO_COLOR)$(CHECKER), $(SWAP) $(LIB) was successfully removed\n"

.PHONY: re
re: fclean all

.PHONY: rec
rec: fclean $(CHECKER)

.PHONY: res
res: fclean $(SWAP)
