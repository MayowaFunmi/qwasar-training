all: my_mastermind

my_mastermind : my_mastermind.c headers.h
	gcc -Wall -Wextra -Werror -o my_mastermind my_mastermind.c headers.h

.PHONY: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f my_mastermind

re: fclean all