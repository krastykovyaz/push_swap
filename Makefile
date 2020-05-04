NAME = checker.a

all: $(NAME)

$(NAME):
	@gcc -c ./*.c -I  ./includes/*.h
	@ar -rc $(NAME) ./*.o
	@rm -rf ./*.o

clean:
	@rm -rf ./*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

test:
	@gcc ./*.c -I ./includes/*.h -o prog
	@./prog 3 2 1 0