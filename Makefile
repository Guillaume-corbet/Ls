##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	main.c		\
			add_to_list.c		\
			init_remove_list.c		\
			long_first.c		\
			long_second.c		\
			algo.c		\
			move.c		\
			reverse.c		\
			ls.c		\
			time.c		\
			init.c		\
			init_remove_list_str.c		\
			add_to_list_str.c		\
			option.c		\
			help.c		\
			max.c		\
			corpse.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_ls

all:	clean fclean $(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf

valgrind:
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf -g3

warning:
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf -Wall -Werror

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean all

auteur:
		echo $(USER) > auteur
