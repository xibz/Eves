//g++ -I <include file path> <CPP file path> `pkg-config --libs --cflags gtk+-2.0`
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <gui.h>
int main(int argc, char *argv[])
{
	sf::RenderWindow App;
	Eves::Menubar mBar;
	Eves::Taskbar tBar;
	GtkWidget *w, *vbox, *area;	
	GdkEventMask m;	
	gtk_init(&argc, &argv);
	Eves::loadWindow(&mBar, &w, &vbox);	
	Eves::loadTaskbar(&tBar, &w, &vbox);
	Eves::setDrawingArea(&w, vbox, &area, &m);

	Eves::handleScreen(area, &App);
	gtk_widget_show_all(w);
	gtk_main();
	return 0;
}
