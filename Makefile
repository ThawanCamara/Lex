NAME		= paragon

LIB_FOLDER	= libs/
SRC_FOLDER	= srcs/
OBJ_FOLDER	= objs/
INC_FOLDER	= includes/

CFLAGS		= -Wall -Wextra -Werror

MAKEFLAGS	+= --no-print-directory

LFLAGS		= $(foreach lib, $(shell ls libs/), -L$(LIB_FOLDER)$(lib) -l$(subst lib,,$(subst .a,,$(lib)))) $(LNK)

#INCLUDES	= -I $(INC_FOLDER) $(shell echo $(foreach lib, $(shell ls libs/), $(shell find $(LIB_FOLDER) -type f) | tr ' ' '\n' | grep .h | sed "s/[a-z]*.h$///g" | uniq))
INCLUDES	= $(shell echo $(foreach lib, $(shell ls $(LIB_FOLDER)), $(shell find $(LIB_FOLDER)$(lib) -type f)) | tr ' ' '\n' | grep \\.h )

SRCS		= $(shell find $(SRC_FOLDER) -type f)

PTH_SRC		= $(shell find $(SRC_FOLDER) -type d)

OBJS		= $(subst $(SRC_FOLDER),$(OBJ_FOLDER),$(subst .c,.o,$(SRCS)))

OBJTOSRC	= $(subst $(OBJ_FOLDER),$(SRC_FOLDER),$(subst .o,.c,$@))

all: objs make_libs $(NAME)

objs:
	mkdir -p $(subst srcs, objs, $(PTH_SRC))

make_libs:
	$(foreach lib, $(shell ls libs/), make -C $(LIB_FOLDER)$(lib))

fclean_libs:
	$(foreach lib, $(shell ls libs/), make fclean -C $(LIB_FOLDER)$(lib))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJS): $(SRCS)
	@if [ "$(OBJTOSRC)" = "$(findstring $(OBJTOSRC),$?)" ]; then \
	printf "$(CC) $(CFLAGS) -c $(OBJTOSRC) -o $@\n"; \
	$(CC) $(CFLAGS) -c $(OBJTOSRC) -o $@; \
	else \
	touch $@; \
	fi

clean:
	rm -rf objs/

fclean: clean fclean_libs 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re make_libs fclean_libs
