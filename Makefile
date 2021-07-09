PARSER		= $(addprefix parser/, ft_atoi.c ft_isdigit.c ft_atof.c ft_isspace.c ft_skip_to_digits.c \
				get_next_line.c get_next_line_utils.c parser.c checker.c parser_utils.c errors.c \
				ft_strlen.c ft_lstnew.c ft_lstadd_back.c ft_lstclear.c  ft_isalpha.c fillers_1.c fillers_2.c ring_list.c \
				ft_memset.c)

VECTOR		= $(addprefix vector_functions/, vector1.c vector2.c  vector3.c vector4.c)

RAYTRACE	= $(addprefix raytrace/, camera.c color_functions.c  cylinder.c  cylinder2.c sphere.c plane.c\
				square.c triangle.c main.c general_intersection.c light_iteration.c light_intersection.c screenshot.c)

HEADERS 	= $(addprefix headers/, minirt.h parser.h vector.h draw.h draw_bonus.h get_next_line.h)

SIZE		= headers/screen_size.m

HEADER	=	-I/headers/

DRAW	= raytrace/draw.c 

BONUS	= raytrace/draw_bonus.c raytrace/threads.c
		
OBJS	= $(PARSER:.c=.o) $(VECTOR:.c=.o) $(RAYTRACE:.c=.o)

BOBJS	= $(BONUS:.c=.o)

DOBJS	= $(DRAW:.c=.o)

NAME	= miniRT

CC		= gcc

RM		= rm -f

CFLAGS	=  -Wall -Wextra -Werror -I/usr/local/include -g

all:		$(NAME)

$(NAME):	$(OBJS) $(DOBJS) $(HEADERS) $(SIZE)
			$(CC) -framework OpenGL -framework Appkit -o $(NAME) $(OBJS) $(DOBJS) $(SIZE) -lmlx

bonus: 		$(OBJS) $(BOBJS) $(HEADERS) $(SIZE)
			 $(CC) -framework OpenGL -framework Appkit -o $(NAME) $(OBJS) $(BOBJS) $(SIZE) -lmlx

clean:
			$(RM) $(OBJS) $(BOBJS) $(DOBJS)

fclean:		clean		
			$(RM) $(NAME)
re:			fclean all

.PHONY:		all clean fclean re
