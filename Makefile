
NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
BONUS = checker

SRC_1 = pushswap.c \

SRC_2 =	llistfunct2.c \
                          instructions2.c \
                          instructions3.c \
                          apply_case.c \
                          instructions.c \
                          get_next_line_utils.c \
                          get_next_line.c \
                          ft_split.c \
                          free.c \
                          validarg.c \
                          ft_error.c\
                          ft_atoi.c \
                          llistfunct.c \
                          mix_min_size.c \
                          ft_min_amount.c \
                          initfunct.c \
                          pushb_3.c \
                          find_move_amount.c \
		
BONUS_SRC = checker.c \
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}


.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS}

all: ${NAME} ${BONUS}

bonus: ${BONUS} ${NAME}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re bonus
