MAKEFLAGS += silent

all:	
	cc -g -Wall -Wextra -Werror -I ../ ft_merge.c ../libft.a

clean:
	$(RM) a.out

run: all
	./a.out ola mundo cruel

.PHONY: all clean run
