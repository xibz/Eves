#ifndef _GUI_H
#define _GUI_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <gtk/gtk.h>
#include <menuBar.h>
#include <taskBar.h>
#ifdef WINDOWS
#include <gdk/gdkwin32.h>
#else
#include <gdk/gdkx.h>
#endif
namespace Eves
{
	void loadWindow(Eves::Menubar *, GtkWidget **, GtkWidget **);
	void loadTaskbar(Eves::Taskbar *, GtkWidget **, GtkWidget **);
	void setDrawingArea(GtkWidget **, GtkWidget * , GtkWidget **, GdkEventMask *);
	bool on_expose(GtkWidget *, GdkEvent *, void *);
	bool on_close(GtkWidget *, void *);
	void handleScreen(GtkWidget *, sf::RenderWindow *);
}
#endif
