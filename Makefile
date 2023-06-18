NAME			=	so_long
BON				=	longishe
SRCS 			=	main.c cre_window.c so_long.c
HEADERS 		=	so_long.h
OBJ 			=	$(SRCS:.c=.o)
CFLAGS 			=	-Wall -Wextra -Werror -Imlx -g -fsanitize=address
IFLAGS			=	-Ilibft
LFLAGS			=	-Llibft -lft
MFLAGS			=	-Lmlx -lmlx -framework OpenGL -framework AppKit
RM				=	rm -rf
BSRC			=	
BHEADERS 		=	#bonus/get_next_line.h bonus/push_bonus.h
BOBJ 			=	$(BSRC:.c=.o)

YELLOW  = \033[33m
PURPLE  = \033[32m
END     = \033[0m

%.o: %.c $(HEADERS)
	@cc -c $(CFLAGS) $(IFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a mlx/libmlx.a
	cc $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) $(MFLAGS) -o $@
	@echo "$(YELLOW) Executable file $(NAME) was compiled $(END)"

FORCE:

libft/libft.a: FORCE
	cd libft && make

mlx/libmlx.a: FORCE
	cd mlx && make

bonus: $(BON)
$(BON): $(BOBJ) libft/libft.a mlx/libmlx.a
	cc $(CFLAGS) $(IFLAGS) $(BOBJ) -L./libft -lft -o $@
	@echo "$(YELLOW) Executable file $(BON) was compiled $(END)"

clean:
	$(RM) $(OBJ) $(BOBJ)
	make -C libft fclean
	@echo "$(PURPLE) Executable file $(NAME) was deleted$(END)"

fclean:	clean
	$(RM) $(NAME) $(BON)
	@echo "$(PURPLE) Executable file $(NAME) was compiled$(END)"
re:	fclean all

.PHONY: all clean fclean re libft bonus

