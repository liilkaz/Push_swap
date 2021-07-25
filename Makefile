NAME		=	push_swap

BONUS_NAME	=	checker

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

HEADER		=	push_swap.h

LIBFT		=	libft.a

SRC			=	instructions_and_init.c instructions_part2.c \
				instructions_part3.c algorithm.c sorting.c \
				big_num_sort.c big_num_sort_part2.c \
				steps.c steps_part2.c utils.c \

WHITE		=	\033[0m
GREEN		=	\033[0;32m
Y			=	\033[0;33m
RED			=	\033[0;31m

all		:	$(NAME)

$(NAME)	:	$(SRC) push_swap.c $(HEADER)
	@$(MAKE) -C libft
	@mv libft/libft.a ./
	@echo "${Y}Libft is compile! ${WHITE}"
	@$(CC) $(CFLAGS) $(SRC) push_swap.c $(LIBFT) -o $(NAME)
	@echo "${GREEN}Bingo! ${WHITE}"

bonus	:	$(SRC) checker.c $(HEADER)
	@$(MAKE) -C libft
	@mv libft/libft.a ./
	@echo "${Y}Libft is compile! ${WHITE}"
	@$(CC) $(CFLAGS) $(SRC) checker.c $(LIBFT) -o $(BONUS_NAME)
	@echo "${GREEN}Bingo, checker is complited!${WHITE}"

clean	:
	@$(RM) libft/*.o
	@echo "${RED}Object files deleted!${WHITE}"

fclean	:	clean
	@$(RM) libft.a $(NAME) $(BONUS_NAME)
	@echo "${RED}Program deleted!${WHITE}"

re		:	fclean all

.PHONY	:	all clean fclean bonus re


