NAME 		=	philo_bonus
#
PREF_OBJB 	=	objb
#
HF_DIR 		=	hf
HEADER 		=	-I$(HF_DIR)
#
SRCSB 		=	main.c
OBJSB 		=	$(patsubst $(PREF_SB)/%.c, $(PREF_OBJB)/%.o, $(SRCSB))
#
CC 			=	cc
FLAGS 		=	-Wall -Werror -Wextra -g
FSANITIZE 	=	-fsanitize=address 
#
bonus:	$(NAME)
			@echo > /dev/null
#
$(NAME):	$(OBJSB)
			@$(CC) $(FLAGS) $(OBJSB) -o $@
			@echo "Bonus executable file "$(NAME)" created successfully!"
#
$(PREF_OBJB)/%.o:	%.c Makefile
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
.PHONY :	all clean fclean re bonus