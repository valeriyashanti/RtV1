# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 15:49:41 by eloren-l          #+#    #+#              #
#    Updated: 2019/02/10 16:12:08 by gkessler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = main.c
SRCS = main.c vec_sc.c cone.c roll.c plane.c on_button_press.c ray_tracing.c compute_light.c get_light.c ray_sphere.c rtv1.c
SRCS_L = $(addprefix libft/,$(SRCS_LNAME))
SRCS_LNAME = ft_atoi.c ft_bzero.c ft_foreach.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_list_at.c ft_list_size.c ft_lstadd.c \
		ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
		ft_push_back.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c ft_lstrevv.c ft_words_count.c ft_clean.c get_next_line.c
OBJECTS = $(SRCS:.c=.o)
OBJECTS_L = $(SRCS_L:.c=.o)
INCLUDES = includes
NAME = rtv1
LIB = libft.a
FLAGS = -I$(INCLUDES)


all: $(NAME)

$(NAME): $(LIB) $(OBJECTS) $(MAIN)
	gcc $(FLAGS) -L. -lft -o $(NAME) $(OBJECTS) -lmlx -framework OpenGl -framework Appkit

$(LIB): $(OBJECTS_L)
	ar rc $@ $^
	ranlib $@

%.o: %.c 
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_L)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
