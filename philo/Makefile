###############
#### SHELL ####
###############

SHELL		= /usr/bin/bash

##############
#### SRCS ####
##############

PATH_SRCS	+= srcs/
PATH_SRCS	+= srcs/diner/
PATH_SRCS	+= srcs/diner/philo_action/
PATH_SRCS	+= srcs/get_args/
PATH_SRCS	+= srcs/print/

### srcs/

SRCS		+= philo.c

### srcs/diner/

SRCS		+= clean_table.c
SRCS		+= init_table.c
SRCS		+= start_diner.c
SRCS		+= init_philo_array.c

### srcs/diner/philo_action/

SRCS		+= philo_routine.c
SRCS		+= philo_states.c

### srcs/get_args/

SRCS		+= ft_atolu_check.c
SRCS		+= get_stat.c

### srcs/print/

SRCS		+= print_philo_act.c
SRCS		+= print_error.c
SRCS		+= print_stat.c

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
