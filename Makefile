NAME = Cub3D

# LIB_DIR = $(shell find lib -type d -maxdepth 1 | grep 'lib/')
# INC_DIR = $(shell find includes -type d) $(foreach dir, $(LIB_DIR), $(shell find -f $(dir)/includes -type d))
LIB_DIR = $(shell find lib -type d)
INC_DIR = $(shell find includes -type d) $(shell find lib -type d)
SRC_DIR = $(shell find src -type d)
OBJ_DIR = obj

SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
LIB = MGL ft mlx
FRAMEWORK = AppKit OpenGL

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

CFLAG = -Werror -Wall -Wextra -fsanitize=address -g
IFLAG = $(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG = $(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )

LFLAG += $(foreach framework, $(FRAMEWORK), -framework $(framework) )

all		: $(NAME)

show	:
	@echo "SRC_DIR : $(SRC_DIR)\n"
	@echo "LIB_DIR : $(LIB_DIR)\n"
	@echo "INC_DIR : $(INC_DIR)\n"
	@echo "CFLAG : $(CFLAG)\n"
	@echo "IFLAG : $(IFLAG)\n"
	@echo "LFLAG : $(LFLAG)\n"
	@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
	@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAG) $(IFLAG) -c $< -o $@

$(NAME)	: $(OBJ)
	@gcc $(CFLAG) $(IFLAG) $(LFLAG) $(OBJ) -o $@

debug : $(NAME)
	@./$(NAME)

install :
	make -C lib/MGL

re-install :
	make -C lib/MGL re

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all
