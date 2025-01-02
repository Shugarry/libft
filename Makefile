CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = placeholder.a
SRC = main.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@make all -C libft
	@$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)
	@echo make done

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo clean done

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo fclean done

#bonus: pondrias make bonus -C libft...

re: fclean all
	
.PHONY: all re clean fclean
