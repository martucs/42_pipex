NAME = pipex

SRCS = pipex.c cmd_utils.c free_msg_utils.c extra_cmd_utils.c

OBJS = $(SRCS:.c=.o) #todos archivos que se llaman igual que los .c pero terminados en .o (aun no creados)

FLAGS = -Wall -Werror -Wextra

CC = cc -g

RM = rm -f

LIBFT = libft/libft.a

#------------------------------------------------

all: makeLibft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

makeLibft:
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

.PHONY: all clean fclean re makeLibft
