SRCFILE =	push_swap.c push_swap2.c ps_dll1.c ps_dll2.c ps_init1.c ps_init2.c \
			ps_stack_utils1.c ps_stack_utils2.c ps_greedy1.c ps_greedy2.c \
			ps_greedy3.c ps_greedy4.c ps_utils.c ps_apply_cmd.c \
			ps_small_data.c
SRCFILE_BONUS = ps_dll1_bonus.c ps_dll2_bonus.c ps_init1_bonus.c \
				ps_init2_bonus.c push_swap_bonus.c ps_stack_utils1_bonus.c \
				ps_stack_utils2_bonus.c push_swap2_bonus.c
SRCS = $(addprefix ./srcs/,$(notdir $(SRCFILE)))
BONUS_SRCS = $(addprefix ./srcs_bonus/,$(notdir $(SRCFILE_BONUS)))
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADERS = push_swap.h
HEADER_DIR = ./header
LIBFT = ./libft/libft.a
TMP_NAME = push_swap
TMP_NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	TARGET_OBJS = $(BONUS_OBJS)
	NAME = checker
else
	TARGET_OBJS = $(OBJS)
	NAME = push_swap
endif

all : $(NAME)

re : fclean all

fclean : clean
	rm -rf $(TMP_NAME)
	rm -rf $(TMP_NAME_BONUS)

clean :
	make -C libft fclean
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

$(NAME) : $(LIBFT) $(TARGET_OBJS)
	$(CC) $(CFLAGS) -Llibft -lft $(TARGET_OBJS) -o $@

%.o : %.c $(HEADER_DIR)/$(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft bonus

bonus :
	make WITH_BONUS=1 all

k :
	echo $(TARGET_OBJS)

.PHONY: all bonus clean fclean re
