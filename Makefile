COLOR	= color.c

EVENT	= key.c \
		mouse.c

matrix	= matrix_determinant.c \
		matrix_inverse.c \
		matrix.c

OBJECTS	= ambient_light.c \
		camera_rotation.c \
		camera.c \
		check.c \
		cylinder.c \
		light.c \
		objects_utils.c \
		objects.c \
		plane.c \
		print.c \
		rays.c \
		sphere.c

PARSING	= parse.c

RAY		= intersect.c \
		ray_cylinder_utils.c \
		ray_cylinder.c \
		ray_plane.c \
		ray_sphere.c \
		utils.c

RENDER	= render.c \
		renderer.c \
		update.c

UTILS	= atof.c \
		clamp.c \
		distance.c \
		map.c \
		pixel_put.c \
		radian.c \
		string_array.c

VECTOR	= atov3.c \
		cross.c \
		dot.c \
		normalize.c \
		vector.c

FILES	+= $(addprefix color/, $(COLOR))
FILES	+= $(addprefix event/, $(EVENT))
FILES	+= $(addprefix matrix/, $(matrix))
FILES	+= $(addprefix objects/, $(OBJECTS))
FILES	+= $(addprefix parsing/, $(PARSING))
FILES	+= $(addprefix ray/, $(RAY))
FILES	+= $(addprefix render/, $(RENDER))
FILES	+= $(addprefix utils/, $(UTILS))
FILES	+= $(addprefix vector/, $(VECTOR))
FILES	+= main.c

SRCS	= $(addprefix srcs/, $(FILES))

OBJS	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	= -std=c99 -Wall -Wextra -Werror -g -fenable-matrix

NAME	= minirt

.SILENT:

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: | lft	$(NAME)

lft:
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -L./libft -lft

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean:	clean
	rm -rf $(NAME)
	make -C libft fclean

re:	fclean all

.PHONY: re fclean clean all