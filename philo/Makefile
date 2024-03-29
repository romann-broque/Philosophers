###############
#### SHELL ####
###############

SHELL		= /usr/bin/bash

##############
#### SRCS ####
##############

PATH_SRCS	+= srcs/
PATH_SRCS	+= srcs/dinner/
PATH_SRCS	+= srcs/dinner/table/
PATH_SRCS	+= srcs/dinner/table/manager/
PATH_SRCS	+= srcs/dinner/table/philosopher/
PATH_SRCS	+= srcs/dinner/table/philosopher/states/
PATH_SRCS	+= srcs/get_args/
PATH_SRCS	+= srcs/print/
PATH_SRCS	+= srcs/time/

### srcs/

SRCS		+= philo.c

### srcs/dinner/

SRCS		+= start_dinner.c
SRCS		+= start_simulation.c

### srcs/dinner/table/

SRCS		+= init_forks.c
SRCS		+= init_philosophers.c
SRCS		+= init_table.c
SRCS		+= set_manager.c
SRCS		+= clean_table.c

### srcs/dinner/table/manager/

SRCS		+= manager_routine.c
SRCS		+= manager_utils.c
SRCS		+= get_manager.c
SRCS		+= start_dinner_time.c

### srcs/dinner/table/philosopher/

SRCS		+= philo_routine.c
SRCS		+= philo_getter.c
SRCS		+= philo_setter.c

### srcs/dinner/table/philosopher/states/

SRCS		+= eat_state.c
SRCS		+= sleep_state.c
SRCS		+= think_state.c

### srcs/get_args/

SRCS		+= ft_atolu_check.c
SRCS		+= init_config.c
SRCS		+= setup_config.c

### srcs/print/

SRCS		+= print_error.c
SRCS		+= print_config.c
SRCS		+= print_philo_action.c

### srcs/time/

SRCS		+= time_utils.c

vpath %.c $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS	+= objs/
OBJS		+= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

##################
#### INCLUDES ####
##################

INCLUDES	+= -I includes/
INCLUDES	+= -I $(LIBFT_FOLDER)/includes

#################
#### HEADERS ####
#################

PATH_HEADERS +=	includes/

HEADERS		+= philo.h

vpath %.h $(PATH_HEADERS)

### NORM

NORM		= ../.git/norm.sh

###############
#### LINKS ####
###############

LINKS		= -pthread

#####################
#### COMPILATION ####
#####################

CC			=	cc

CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-g3

ifneq ($(no_error), true)
	CFLAGS		+=	-Werror
endif

ifeq ($(debug), true)
	CFLAGS	+= -fsanitize=undefined,thread
endif

ifeq ($(print_debug), true)
	CFLAGS	+= -D PRINT_DEBUG=true
endif

ifeq ($(dont_wait), true)
	CFLAGS	+= -D DONT_WAIT=true
endif

##############
#### NAME ####
##############

NAME		+= philo

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

ifndef ECHO
T := $(words $(SRCS))
N := x
C = $(words $N)$(eval N := x $N)

ECHOC = echo -ne "\r\033[2K"
ECHO = $(ECHOC) $(ORANGE) "[`expr $C '*' 100 / $T`%]"
endif

###############

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) $(LINKS)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(OBJS) : $(PATH_OBJS)/%.o: %.c Makefile $(HEADERS)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

run : all
	$(ECHOC) $(GREEN) "RUNNING $(NAME)"$(NC)"\n\n"
	./$(NAME)

norm :
	$(ECHOC) $(BLUE) "\n""NORM : "$(NC)""
	./$(NORM)

clean	:
	$(RM) -r $(PATH_OBJS)
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean	:	clean
	# $(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"

re 		: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY	: all run norm clean fclean re
.SILENT	:
