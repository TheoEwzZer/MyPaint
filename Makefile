##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	my_paint

CC		=	gcc -g3
RM		=	rm -rf

SRC		=	$(shell find src -type f -name "*.c")

OBJ		=	$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
LIB		=	-Llib/my -lmy -lm -Iinclude
WARN1 = 	-W -Wall -Wextra
WARN2 = 	-Wconversion -Wunsuffixed-float-constants -Wmissing-prototypes \
			-Wcast-qual -Wswitch-default -Wunreachable-code \
			-Wmissing-declarations -Wsequence-point \
			-pedantic -Wformat-nonliteral -Wformat-signedness \
			-Wfloat-equal -Wundef -Wwrite-strings -Wcast-align \
			-Wstrict-overflow=5 -Wdeclaration-after-statement
WARN3 = 	-Wunused-macros -Warith-conversion -Wmissing-include-dirs \
			-Wunused-parameter -Wuninitialized -Wduplicated-branches \
			-Wmissing-include-dirs -Wparentheses \
			-Wduplicated-cond -Wshadow -Wformat-truncation=2 \
			-Wformat-overflow -Wformat-security -Wformat=2 -Wnull-dereference \
			-Wold-style-definition

$(NAME):
		@make -s -C lib/my
		@$(CC) -o $(NAME) $(SRC) $(WARN1) $(WARN2) $(WARN3) $(LIB) $(CSFML)
		@rm lib/libmy.a
		@rm lib/my/libmy.a
		@make -s clean

all:	$(NAME)

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
