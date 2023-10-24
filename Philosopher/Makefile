NAME		=	philo

HEAD_DIR	=	./include/
HEAD		=	philo.h
HEADS		=	$(addprefix $(HEAD_DIR), $(HEAD))

SRCS_DIR	=	./srcs/
SRCS		=	main.c\
				init.c\
				philo_action.c\
				philo_threads.c\
				philo_utils.c\

OBJS_DIR	=	./objs/
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)%.o)

CC			=	cc
CC_FLAG		=	-Wall -Wextra -Werror -pthread

RM			=	rm -rf


all:		$(NAME)

$(OBJS)	:	$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADS)
			mkdir -p $(OBJS_DIR)
			$(CC) $(CC_FLAG) -I$(HEAD_DIR) -c $< -o $@

$(NAME)	:	$(OBJS)
			$(CC) $(CC_FLAG) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS_DIR)

fclean	:	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY	:	all clean fclean re
