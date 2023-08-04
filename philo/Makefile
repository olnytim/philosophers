NAME 		=	philo
#
PREF_OBJ 	=	obj
#
HEADER 		=	-I.
#
SRCS 		=	main.c parse.c init.c the_end.c time.c
OBJS 		=	$(patsubst %.c, $(PREF_OBJ)/%.o, $(SRCS))
DEPS 		=	$(OBJS:.o=.d)
#
CC 			=	cc
FLAGS 		=	-Wall -Werror -Wextra -g
FSANITIZE 	=	-fsanitize=address 
#
all:	$(NAME)
			@echo > /dev/null
#
$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $@
			@echo "Executable file "$(NAME)" created successfully!"
#
$(PREF_OBJ)/%.o:	%.c Makefile
			@mkdir -p $(PREF_OBJ)
			@$(CC) $(FLAGS) $(HEADER) -MMD -c $< -o $@
#
-include $(DEPS)
#
clean:
			@rm -rf $(PREF_OBJ)
#
fclean:		clean
			@rm -f $(NAME)
#
re:			fclean all
#
.PHONY :	all clean fclean re bonus