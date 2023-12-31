# This is a minimal set of ANSI/VT100 color codes
END			=	\e[0m
BOLD		=	\e[1m
UNDER		=	\e[4m
REV			=	\e[7m

# Colors

DEF_COLOR 	= 	\033[0;39m
GRAY 		= 	\033[0;90m
GREY_01		=	\033[30m
RED 		= 	\033[0;91m
RED_01		=	\033[31m
GREEN 		= 	\033[0;92m
GREEN_01	=	\033[32m
YELLOW 		= 	\033[0;93m
YELLOW_01	=	\033[33m
BLUE 		= 	\033[0;94m
BLUE_01		=	\033[34m
PURPLE		=	\033[35m
MAGENTA 	= 	\033[0;95m
CYAN 		= 	\033[0;96m
CYAN_01		=	\033[36m
WHITE 		= 	\033[0;97m
WHITE_01	=	\033[37m

# Inverted, i.e. colored backgrounds
IGREY		=	\e[40m
IRED		=	\e[41m
IGREEN		=	\e[42m
IYELLOW		=	\e[43m
IBLUE		=	\e[44m
IPURPLE		=	\e[45m
ICYAN		=	\e[46m
IWHITE		=	\e[47m

# **************************************************************************** #

#Variables‹

NAME			= push_swap
INCLUDE			= include/
LIBFT			= libft
SRC_DIR			= src/
UTILS_DIR		= utils/
MOVES_DIR 		= moves/
SWAP_DIR		= swap/
REVERSE_DIR		= reverse/
ROTATION_DIR	= rotation/
PUSH_DIR		= push/
CONDITIONS_DIR 	= conditions/
OBJ_DIR			= obj/
OBJ_DIR_TEST	= obj_test/
TEST_DIR		= test/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g3 -I
RM				= rm -f
AR				= ar rcs

# =========================================================================== #


#Sources

SRC_FILES	=	main ft_sort ft_error
CONDITIONS 	=	ft_stack_is_correct
SWAP		=	ft_swap_a ft_swap_b ft_swap_ss
PUSH		=	ft_push_a ft_push_b
ROTATION	=	ft_rotate_a ft_rotate_b ft_rotate_s
REVERSE		=	ft_reverse_a ft_reverse_b ft_reverse_s
MOVES 		= 	$(addprefix $(SWAP_DIR),$(SWAP)) \
				$(addprefix $(PUSH_DIR),$(PUSH)) \
				$(addprefix $(ROTATION_DIR),$(ROTATION)) \
				$(addprefix $(REVERSE_DIR),$(REVERSE)) 
UTILS		= 	stack_mem stack_num pile_utils pile_utils_2 pile_utils_3 pile_utils_4 instructions ft_sort_three ft_sort_big ft_calculate_pos\
				$(addprefix $(MOVES_DIR),$(MOVES)) 


SRC_FILES+=$(addprefix $(UTILS_DIR),$(UTILS))
SRC_FILES+=$(addprefix $(CONDITIONS_DIR),$(CONDITIONS))


# Files 

SRCS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(CC) $(OBJS) -o $(NAME) $(LIBFT)/libft.a
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(UTILS_DIR)
			@mkdir -p $(OBJ_DIR)$(UTILS_DIR)$(MOVES_DIR)
			@mkdir -p $(OBJ_DIR)$(UTILS_DIR)$(MOVES_DIR)$(SWAP_DIR)
			@mkdir -p $(OBJ_DIR)$(UTILS_DIR)$(MOVES_DIR)$(PUSH_DIR)
			@mkdir -p $(OBJ_DIR)$(UTILS_DIR)$(MOVES_DIR)$(ROTATION_DIR)
			@mkdir -p $(OBJ_DIR)$(UTILS_DIR)$(MOVES_DIR)$(REVERSE_DIR)
			@mkdir -p $(OBJ_DIR)$(CONDITIONS_DIR)

# Rules

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf utils/
			@make clean -C $(LIBFT)
			@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME2)
			@$(RM) -f $(NAME_TEST)
			@$(RM) -f $(NAME_DEBUG)
			@$(RM) -f $(LIBFT)/libft.a
			@$(RM) -f $(TEST_DIR)/libft.a
			@$(RM) -f libft.a
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"
			@echo "$(GREY)                                     ..                                      "
			@echo "$(GREEN)                           .:---===++++*++==-:.                              "
			@echo "$(YELLOW)                      .:-=++==--------++***#*+++=-.                          "
			@echo "$(BLUE)                  .-=++=--------------------=+****++=:.                      "
			@echo "$(MAGENTA)               .-+*=-----------------------------+*+=++=-                    "
			@echo "$(CYAN)             .=*#*+---------------------------------=*#*++=.                 "
			@echo "$(RED_01)           :=*#*=------------::::::::::::--------------=##=+=.               "
			@echo "$(GRAY)         .++#*=--------------::::::::::::----------------+%==+-              "
			@echo "$(GREEN)        .**#=---------------------------------------------=#*=++.            "
			@echo "$(RED)       :*+%=-----------------------------------------------=====*.           "
			@echo "$(YELLOW)      :*=%=-----------------------------------------------======+=           "
			@echo "$(MAGENTA)     .*==+---------------=--------------------------------=======#.          "
			@echo "$(CYAN)    .*=======-------=--==--------------------------------========*+          "
			@echo "$(WHITE)    +===============---===-----------------------------===========#.         "
			@echo "$(GREEN_01)    *==============----=--==------------------------==============+=         "
			@echo "$(RED)   :*=================-==-====-------===---------==================*.        "
			@echo "$(GREEN)   =+==================================----========================*:        "
			@echo "$(MAGENTA)   +=================================================================        "
			@echo "$(YELLOW)   +================================================================*        "
			@echo "$(BLUE)   =+===============================================================*        "
			@echo "$(MAGENTA)   :*===============================================================*        "
			@echo "$(CYAN)   .*===============================================================*-*+     "
			@echo "$(PURPLE)    ++==============================================================%%=%.    "
			@echo "$(WHITE) :=--*==========+=+++++++++**++===========+***######**#*****+=====*%%==#     "
			@echo "$(GRAY) +=+%%*===*#***%+++====+++++++%@+========%+-=*:..:::-------=##==*%%%++%-     "
			@echo "$(RED_01) ++=*%%%*=%%:-#+:.::::::::::---*@========%=+#+.....:::::::::-%+%%%@*##%      "
			@echo "$(BLUE) :**++%%%%%%:*+#....:::::::::::-#*+**##*+%=+#=.  ....::::::::%%#%#+##+#      "
			@echo "$(BLUE_01)  -***+#@%%%::#-.....::::::::::-=@%%%%%%@@==-:.......:::::::-#@%++##=#=      "
			@echo "$(GREEN)   -**+=+#@%-:::....::::::::::---%@*+++*#@=-:::......::::::--##==#*=#-       "
			@echo "$(GREEN_01)    -*#+=++%:::::::::::::::::----%+======*#-:::::::::::::::--%+====%-        "
			@echo "$(MAGENTA)     #*#=++@-:::::::::::::-----=##========##+=--:::::::---=+%#++==+#         "
			@echo "$(PURPLE)     ++=##=*#+=======++*****###**+=========++*********#####*+=+%+#+*         "
			@echo "$(CYAN)   .:*++@*===+****++++=============++++=======================+%%%%#:        "
			@echo "$(RED)   :*#%%%*=====================+=======+==+===================+%##%#:        "
			@echo "$(WHITE)   =*#%%%+====================+*===========#==================#%#%%-         "
			@echo "$(BLUE)   ..-*%%#%===================+*+======+*=+*=================#%###%.         "
			@echo "$(WHITE_01)      :%%#%#+===================**#%###%#*=================+%%#####:         "
			@echo "$(MAGENTA)      +%###%%#================*#%%%%%%%%%%%%#+===========+*%######%+         "
			@echo "$(BLUE_01)      :%#####%%+============#%####%%##%%#####%##+=======*%%#######%-         "
			@echo "$(GREEN)      -%%######%%+========%%#####%%%#%%%%%%#####%*====*%%#########%:         "
			@echo "$(PURPLE)       :%########%#=+==+#%###%%%%##%%#%####%%%%##%*+##%###########%-         "
			@echo "$(RED)        *%%########%%#%%###%%#######%%%########%###%##############%=         "
			@echo "$(CYAN)        #%#############%%%*+###################*#%%%#############%%+.        "
			@echo "$(BLUE)        .%%##############%*+==+*###########%#*==+#%#################%.       "
			@echo "$(MAGENTA)        .%################%*+++===*%%%%%%%@+=++++#%#################%.       "
			@echo "$(GREEN_01)        =%#################%%++++++%######%++++++%#################%=        "
			@echo "$(PURPLE)        .%###################%%#*+++%####%**+++*%%################%=         "
			@echo "$(RED_01)         -%#####################%%%#%%%%@%%%%%%###################%-         "
			@echo "$(PURPLE)         =#%####################################################%%=          "
			@echo "$(GREEN)          .%%###################################################%=           "
			@echo "$(GRAY)           :=%#%##############################################%#%-           "
			@echo "$(BLUE)             ==+#%##%%#####################################%#%+-.            "
			@echo "$(WHITE)                 .==-#%##%#################################%#+               "
			@echo "$(CYAN)                        .+%#%@#######################%#%@%%+                 "
			@echo "$(RED)                          :---*#%%%##%######%##%%%#%#=+=.:.                  "
			@echo "$(GREEN_01)                                  =*#@%%%%#%%%%#.:-:                         "
			@echo "$(RED_01)                                     .:==:-:...                              "

.PHONY:		all clean fclean re

