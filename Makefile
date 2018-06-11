##
## EPITECH PROJECT, 2017
## lemin
## File description:
## Makefile for lem_in.
##

SRC_RES_DIR	=	$(realpath src/get_resources)

SRC_SOLVE_DIR	=	$(realpath src/solve)

SRC_RES		=	$(SRC_RES_DIR)/resources.c		\
			$(SRC_RES_DIR)/ants/ants.c		\
			$(SRC_RES_DIR)/ants/get_ants.c		\
			$(SRC_RES_DIR)/rooms/rooms.c		\
			$(SRC_RES_DIR)/rooms/get_rooms.c	\
			$(SRC_RES_DIR)/rooms/get_stats_room.c	\
			$(SRC_RES_DIR)/rooms/commands.c		\
			$(SRC_RES_DIR)/rooms/error_rooms.c	\
			$(SRC_RES_DIR)/tunnels/tunnels.c	\
			$(SRC_RES_DIR)/tunnels/get_tunnels.c	\
			$(SRC_RES_DIR)/tunnels/get_links.c

SRC_SOLVE	=	$(SRC_SOLVE_DIR)/solve.c				\
			$(SRC_SOLVE_DIR)/path.c					\
			$(SRC_SOLVE_DIR)/breadth_search/breadth_search.c	\
			$(SRC_SOLVE_DIR)/breadth_search/rate_rooms.c		\
			$(SRC_SOLVE_DIR)/breadth_search/get_paths.c		\
			$(SRC_SOLVE_DIR)/breadth_search/get_next_room.c		\
			$(SRC_SOLVE_DIR)/move_ants/share_ants.c			\
			$(SRC_SOLVE_DIR)/move_ants/move_ants.c

SRC		=	src/main.c	\
			src/utilities.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_RES:.c=.o)	\
			$(SRC_SOLVE:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=	-Llib/ -lmy

NAME		=	lem_in

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) -f $(OBJ)

fclean	:	clean
		$(RM) -f $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re
