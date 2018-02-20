CC	=	gcc

NAME = not_mg_vr.a

COMPILE_PATH = ./bin/

SRC =	./libmy/my_putchar.c \
		./libmy/my_isneg.c \
		./libmy/my_put_nbr.c \
		./libmy/my_swap.c \
		./libmy/my_putstr.c \
		./libmy/my_strlen.c \
		./libmy/my_getnbr.c \
		./libmy/my_strcpy.c \
		./libmy/my_strncpy.c \
		./libmy/my_strcmp.c \
		./libmy/my_strncmp.c \
		./libmy/my_strcat.c \
		./libmy/my_strncat.c \
		./libmy/my_strstr.c \
		./libmy/my_strdup.c \
		./libmy/my_str_to_wordtab.c \
		./libmy/my_putstr_err.c \
		./src/deplacements.c \
		./src/orientation.c \
		./src/position.c \
		./src/actions.c \
		./src/inventory.c \
		./src/maps.c

OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -f

CFLAGS = -Wall -Werror

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			$(CC) ./main.c ./not_mg_vr.a
			mv ./a.out ./not_mg


all:	$(NAME)

clean:	
		$(RM) $(OBJ)
		$(RM) ./src/*.o
		$(RM) ./libmy/*.o

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(OBJ)


re:		fclean all

.PHONY: all clean fclean re