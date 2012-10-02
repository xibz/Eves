CC=g++
CFLAGS=
IFLAGS=-I ./includes/
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system `pkg-config --libs --cflags gtk+-2.0`
FILES= ./GUI/gui.cpp ./GUI/aboutWindow.cpp
#all: guiCore.o eves
#eves:	guiCore.o
#		$(CC) -o eves guiCore.o

guiCore.o:	./GUI/gui.cpp ./includes/gui.h
				$(CC) $(IFLAGS) -o eves main.cpp $(FILES) $(LDFLAGS)
clean:
	\rm *.o *~ eves
