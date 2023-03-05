# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/13 20:26:36 by smclacke      #+#    #+#                  #
#    Updated: 2023/03/05 21:54:48 by smclacke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/
ARCHIVE = ar -rcs
RM = rm -f

LIBFT_DIR	=	libft/
LIBFT	=	ft_isalpha.c	\
    ft_isalnum.c	\
    ft_isascii.c	\
    ft_isdigit.c	\
    ft_isprint.c	\
	ft_isspace.c	\
	ft_ishex.c		\
    ft_strchr.c		\
    ft_strrchr.c	\
    ft_strlen.c		\
    ft_strnstr.c	\
    ft_strncmp.c	\
    ft_strlcat.c	\
    ft_strlcpy.c	\
    ft_atoi.c		\
	ft_atof.c		\
    ft_bzero.c		\
    ft_memset.c		\
    ft_memcpy.c		\
    ft_memcmp.c		\
    ft_memmove.c	\
    ft_memchr.c		\
    ft_tolower.c	\
    ft_toupper.c	\
    ft_calloc.c		\
    ft_strdup.c		\
    ft_putchar_fd.c	\
    ft_putendl_fd.c	\
    ft_putnbr_fd.c	\
    ft_putstr_fd.c	\
    ft_strjoin.c	\
    ft_substr.c		\
    ft_striteri.c	\
    ft_strtrim.c	\
	ft_strcmp.c		\
    ft_strmapi.c	\
    ft_itoa.c		\
    ft_split.c		\
	ft_lstadd_back.c	\
    ft_lstadd_front.c	\
	ft_lstclear.c		\
    ft_lstdelone.c		\
    ft_lstiter.c		\
    ft_lstlast.c		\
    ft_lstmap.c			\
    ft_lstnew.c			\
    ft_lstsize.c		\


PRINTF_DIR	=	printf/
PRINTF		=	ft_printf.c		\
				ft_printf_utils.c\

GNL_DIR	=	gnl/
GNL		=	get_next_line.c		\
			get_next_line_utils.c\

SRC_DIR	:=	src/
SRCS +=$(addprefix $(LIBFT_DIR),$(LIBFT))
SRCS +=$(addprefix $(PRINTF_DIR),$(PRINTF))
SRCS +=$(addprefix $(GNL_DIR),$(GNL))

SRCP = $(addprefix $(SRC_DIR),$(SRCS))

OBJ_DIR	:=	obj/
OBJS :=	$(SRCS:.c=.o)
OBJP :=	$(addprefix $(OBJ_DIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJP)
	@$(ARCHIVE) $(NAME) $(OBJP)
	@ echo "Made!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)	
	@mkdir -p $(OBJ_DIR)$(LIBFT_DIR)
	@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)
	@mkdir -p $(OBJ_DIR)$(GNL_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@ echo "Clean!"

fclean: clean
	@$(RM) -f $(NAME)
	@ echo "fCleaned!"

re: fclean all

.PHONY: all clean fclean re