#make file - this is a comment section

INC=-I/home/zequnl/Installs/include -I/home/zequnl/Installs/src/libsharp
LIB=-L/home/zequnl/Installs/lib
LINKS=-lsharp2 -lc_utils -lgomp -lm -lfftpack

all:    #target name
	gcc main.c -o main $(INC) $(LIB) $(LINKS)