NAME = pipex

SRCS = pipex.c new_split.c

OBJS = $(SRCS:.c=.o) #todos archivos que se llaman igual que los .c pero terminados en .o (aun no creados)

FLAGS = -Wall -Werror -Wextra

CC = cc -g

RM = rm -f

LIBFT = libft/libft.a

#------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(LIBFT):
	make -C libft

%.o:%.c Makefile pipex.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
