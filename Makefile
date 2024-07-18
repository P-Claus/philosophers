#############################################
###		 CONFIG		          ###
#############################################

NAME			= philo

CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Werror -Wextra -g $(INCLUDES) -pthread

MKDIR			= mkdir -p

SOURCES_DIR		= src
SOURCE_FILES	= argv_is_not_int.c argv_is_not_numeric.c main.c init_data.c \
			  	init_philosophers.c dinner_party.c monitor.c cleanup.c ft_usleep.c \
			  	get_time.c getters_and_setters.c parse_input.c print_error.c \
			 	synchronization_functions.c write_status.c

SOURCES			= $(addprefix $(SOURCES_DIR)/, $(SOURCE_FILES))

OBJ				= $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))
OBJ_DIR			= obj


INCLUDES		= -I ./includes

TOTAL_FILES 	= $(words $(SOURCE_FILES)) 

COMPILE_COUNT 	= 0

#############################################
###		COLORS			  ###
#############################################

RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET_COLOR		= \033[0m
MOVEUP			= \033[F
RESET			= \e[2K\r

#############################################
###		 RULES	      	     	  ###
#############################################

all: $(NAME)

$(NAME): $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ)
	@echo "$(RESET)$(GREEN)Compiled $(NAME)$(RESET_COLOR)"

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling philo $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling philo $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(ERROR_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling philo $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Removed the object files$(RESET_COLOR)"

fclean:
	@make clean -s
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)Removed $(NAME)$(RESET_COLOR)"

re:
	@make -s fclean
	@make -s

.PHONY:			all clean fclean re 
