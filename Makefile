
BK		:= \033[30;1m
R		:= \033[31;1m
G		:= \033[32;1m
Y		:= \033[33;1m
B		:= \033[34;1m
M		:= \033[35;1m
C		:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I -I./$(INCDIR)

SRCS = 	src/assign.c src/cost.c src/cases.c src/rev_rot.c src/error.c src/main.c src/move.c src/rotate.c src/push.c src/sort.c src/init_stacks.c src/swap.c src/utils.c src/get_target.c src/lists.c

SRCDIR = src/
OBJDIR = bin/
INCDIR = include/

LIBFTA = libft/libft.a
INC = include/push_swap.h

OBJS = $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

$(NAME): lib $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFTA) $(OBJS) -o $(NAME)
	@echo "$(Y)PUSH SWAP UP TP DATE$(RESET)"

lib: 
	@mkdir -p bin
	@$(MAKE) -C libft

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	@echo "$(G)Compiling: $(B)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)
	@rm -rf bin
	@echo "$(R)Cleaning...$(RESET)"
	
fclean: clean
	@$(MAKE) -C libft fclean
	@rm -rf $(NAME)
	@echo "$(R)FCleaning...$(RESET)"

re: fclean all
	
