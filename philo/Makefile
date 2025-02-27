# VALGRIND
VALGRIND_LOG := valgrind.log


# COLORS
GREEN := \033[32m
RED := \033[31m
CYAN := \033[36m
VIOLET := \033[38;5;208m
COLOR_LIMITER := \033[0m


# NAME
NAME := philo


# FLAGS
CFLAGS := -Wall -Wextra -g3 -Werror

# PATHS
HEADER_PATH := ./includes/
SRC_PATH := ./src/
BIN_PATH := ./bin/
UTILS_PATH := ./utils/

# SOURCES AND OBJECTS
FILES := \
	exec.c \
	task.c \
	init.c \
	main.c \
	thread.c \
	errors.c \
	validation.c \
	$(UTILS_PATH)lib.c \
	$(UTILS_PATH)time.c \
	$(UTILS_PATH)utils.c \
	$(UTILS_PATH)ft_mutex.c \
	$(UTILS_PATH)ft_malloc.c 
SRCS := $(addprefix $(SRC_PATH), $(FILES))
OBJS := $(addprefix $(BIN_PATH), $(FILES:%.c=%.o))

all: $(BIN_PATH) print $(NAME)

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)$(UTILS_PATH)

print:
ifeq ($(wildcard $(NAME)),)
	@printf "$(GREEN) ------------------------$(COLOR_LIMITER)"
	@printf "$(GREEN)| Compiling Main Project |$(COLOR_LIMITER)"
	@printf "$(GREEN)------------------------$(COLOR_LIMITER)"
	@echo " "
endif

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADER_PATH)
	@printf "$(CYAN)------ --------------------------------------------- ------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------| PHILO executable was created successfully!! |------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------ --------------------------------------------- ------$(COLOR_LIMITER)\n"
	@echo " "

$(BIN_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)...\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_PATH)

clean:
	@printf "$(RED)[Removing Objects...]$(COLOR_LIMITER)\n"
	@rm -rf $(BIN_PATH)
	@rm -rf $(VALGRIND_LOG)

fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)\n"
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

valgrind: all
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--track-fds=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--errors-for-leak-kinds=definite \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) 10 2 3 4
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re print valgrind