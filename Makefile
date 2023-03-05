NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	check_duplicate.c ft_atoi.c ft_split.c ft_strlen.c get_list.c reverse_rotate.c sort_100.c swap.c \
		ft_exit.c ft_strdup.c ft_strtrim.c is_sorted.c push.c rotate.c sort_3.c ft_lstadd_back.c ft_strncmp.c\
		add_first.c create_elt.c ft_memcpy.c ft_strjoin.c ft_substr.c size_list.c sort_5.c main.c list_tab.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
