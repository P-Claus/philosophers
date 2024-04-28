#############################################
###		 			CONFIG		          ###
#############################################

NAME			= philosopers

CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Werror -Wextra -g $(INCLUDES) -pthread

MKDIR			= mkdir -p

SOURCES_DIR		= src
SOURCES			= main.c init_data.c init_philosophers.c dinner_party.c monitor.c
OBJ				= $(OBJ_DIR)/main.o $(OBJ_DIR)/init_data.o $(OBJ_DIR)/init_philosophers.o $(OBJ_DIR)/dinner_party.o $(OBJ_DIR)/monitor.o
OBJ_DIR			= obj

UTILS_DIR 		= utils
UTILS_FILES		= print_error.c print_success.c parse_input.c ft_usleep.c get_time.c getters_and_setters.c synchronization_functions.c write_status.c cleanup.c
UTILS_OBJ		= $(OBJ_DIR)/print_error.o $(OBJ_DIR)/print_success.o $(OBJ_DIR)/parse_input.o $(OBJ_DIR)/ft_usleep.o $(OBJ_DIR)/get_time.o $(OBJ_DIR)/getters_and_setters.o $(OBJ_DIR)/synchronization_functions.o $(OBJ_DIR)/write_status.o $(OBJ_DIR)/cleanup.o

ERROR_DIR 		= error_checks
ERROR_FILES		= check_if_string_is_numeric.c check_if_string_is_int.c
ERROR_OBJ		= $(OBJ_DIR)/check_if_string_is_numeric.o $(OBJ_DIR)/check_if_string_is_int.o



INCLUDES		= -I ./includes

TOTAL_FILES := $(words $(wildcard $(SOURCES_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c))

COMPILE_COUNT = 0

#############################################
###					COLORS			      ###
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
###		 			RULES	      	      ###
#############################################

all: $(NAME)

$(NAME): $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ)
	@echo "$(RESET)$(GREEN)Compiled $(NAME)$(RESET_COLOR)"

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling philosophers $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling philosopers $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(ERROR_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling philosophers $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Removed the object files$(RESET_COLOR)"

fclean:
	@make clean -s
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)Removed $(NAME) and the object files$(RESET_COLOR)"

re:
	@make -s fclean
	@make -s

.PHONY:			all clean fclean re 