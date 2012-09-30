CC=g++
CFLAGS=
IFLAGS=-I ./includes/
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system `pkg-config --libs --cflags gtk+-2.0`
#all: guiCore.o eves
#eves:	guiCore.o
#		$(CC) -o eves guiCore.o

guiCore.o:	./GUI/gui.cpp ./includes/gui.h
				$(CC) $(IFLAGS) -o guiCore.o main.cpp ./GUI/gui.cpp $(LDFLAGS)
clean:
	\rm *.o *~ eves
