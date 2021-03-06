all:
	gcc -Wall -Werror -o chessviz chessviz.c
clean:
	$(RM) chessviz
