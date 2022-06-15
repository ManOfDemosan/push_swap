NAME			:= push_swap
BONUS			:= checker
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
RM				:= rm -f

LIBFT_DIR		:= ./libft
LIBFT_LIB		:= ./libft/libft.a

INCLUDE			:= ./include/
INCLUDE_FILE	:= $(addprefix $(INCLUDE), push_swap.h)

SRCS			:= $(addprefix ./src/, \
					case_small.c\
					case_large.c\
					init_stack.c \
					main.c \
					operation.c\
					operation1.c\
					operation2.c\
					pharse.c\
					stack_handler.c)
OBJS_FILE		:= $(SRCS:.c=.o)

SRCS_BONUS			:= $(addprefix ./src/, \
					checker.c\
					case_small.c\
					case_large.c\
					init_stack.c \
					operation_b.c\
					operation_b1.c\
					operation_b2.c\
					pharse.c\
					stack_handler.c)
 OBJS_FILE_BONUS		:= $(SRCS_BONUS:.c=.o)

ifdef CHECKER
		OBJ_FILE		= $(OBJS_FILE_BONUS)
		NAMES			= $(BONUS)
else
		OBJ_FILE		= $(OBJS_FILE)
		NAMES			= $(NAME)
endif

.PHONY	: all
all		: libft $(NAMES)

$(NAMES)	: $(OBJ_FILE) $(INCLUDE_FILE)
		$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJ_FILE) -g -o $(NAMES)

%.o		: %.c
		$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_DIR) -g -c $< -o $@

.PHONY	: bonus
bonus	:
		@make CHECKER=1 all

.PHONY	: libft
libft	:
		@make -C ./libft all

.PHONY	: clean
clean	:
		@make -C ./libft clean
		@$(RM) $(OBJS_FILE) $(OBJS_FILE_BONUS)

.PHONY	: fclean
fclean	: clean
		@make -C ./libft fclean
		@$(RM) $(NAME) $(BONUS)

.PHONY	: re
re		: fclean all