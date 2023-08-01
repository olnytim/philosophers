NAME 		=	philo
NAME_B 		=	philo_bonus
#
LIBFT_PATH 	=	libft
LIBFTA 		=	$(LIBFT_PATH)/libft.a
#
PREF_S 		=	philo
PREF_OBJ 	=	obj
#
PREF_SB 	=	philo_bonus
PREF_OBJB 	=	objb
#
HF_DIR 		=	hf
HEADER 		=	-I$(HF_DIR)
#
SRCS 		=	$(addprefix $(PREF_S)/, )
OBJS 		=	$(patsubst $(PREF_S)/%.c, $(PREF_OBJ)/%.o, $(SRCS))
DEPS 		=	$(OBJS:.o=.d)
#
SRCSB 		=	$(addprefix $(PREF_SB)/, )
OBJSB 		=	$(patsubst $(PREF_SB)/%.c, $(PREF_OBJB)/%.o, $(SRCSB))
#
CC 			=	cc
FLAGS 		=	-Wall -Werror -Wextra -g
FSANITIZE 	=	-fsanitize=address 
#
all:	$(NAME)
			@echo > /dev/null
#
$(NAME):	$(OBJS) $(LIBFTA)
			@$(CC) $(FLAGS) $(OBJS) $(LIBFTA) -o $@
			@echo "Executable file "$(NAME)" created successfully!"
#
$(PREF_OBJ)/%.o:	$(PREF_S)/%.c Makefile
			@mkdir -p $(PREF_OBJ)
			@$(CC) $(FLAGS) $(HEADER) -MMD -c $< -o $@
#
$(LIBFTA):
			@make -C $(LIBFT_PATH)
#
bonus:	$(NAME_B)
			@echo > /dev/null
#
$(NAME_B):	$(OBJSB) $(LIBFTA)
			@$(CC) $(FLAGS) $(OBJSB) $(LIBFTA) -o $@
			@echo "Bonus executable file "$(NAME_B)" created successfully!"
#
$(PREF_OBJB)/%.o:	$(PREF_SB)/%.c Makefile
			@mkdir -p $(PREF_OBJB)
			@$(CC) $(FLAGS) $(HEADER) -MMD -c $< -o $@
#
-include $(DEPS)
#
clean:
			@rm -rf $(PREF_OBJ)
			@rm -rf $(PREF_OBJB)
			@$(MAKE) -C $(LIBFT_PATH) clean
#
fclean:		clean
			@rm -f $(NAME)
			@rm -f $(NAME_B)
			@rm -f $(LIBFTA)
#
re:			fclean all
#
.PHONY :	all clean fclean re bonus