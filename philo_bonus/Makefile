NAME 		=	philo_bonus
#
PREF_SB 	=	srcb
PREF_OBJB 	=	objb
#
HF_DIR 		=	hf
HEADER 		=	-I$(HF_DIR)
#
SRCSB 		=	$(addprefix $(PREF_SB)/, main.c parse.c init.c the_end.c time.c philo.c you_are_dead.c)
OBJSB 		=	$(patsubst $(PREF_SB)/%.c, $(PREF_OBJB)/%.o, $(SRCSB))
DEPS 		=	$(OBJSB:.o=.d)
#
CC 			=	cc
FLAGS 		=	-Wall -Werror -Wextra -g
#
all:	$(NAME)
			@echo > /dev/null
#
$(NAME):	$(OBJSB)
			@$(CC) $(FLAGS) $(OBJSB) -o $@
			@echo "Bonus executable file "$(NAME)" created successfully!"
#
$(PREF_OBJB)/%.o:	$(PREF_SB)/%.c Makefile
			@mkdir -p $(PREF_OBJB)
			@$(CC) $(FLAGS) $(HEADER) -MMD -c $< -o $@
#
-include $(DEPS)
#
clean:
			@rm -rf $(PREF_OBJB)
#
fclean:		clean
			@rm -f $(NAME)
#
re:			fclean all
#
.PHONY :	all clean fclean re
