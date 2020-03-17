#make file - this is a comment section

INC=-I/home/zequnl/Installs/include
LIB=-L/home/zequnl/Installs/lib
LINKS=-lsharp -lc_utils -lgomp -lm -lfftpack

all:    #target name
	gcc main.c -o main $(INC) $(LIB) $(LINKS)