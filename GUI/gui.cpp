/*
	Handles GUI
	Will basically load the window, menubar, and taskbar
	Will also handle the drawing area for SFML
	@author Ben Powell
*/
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
	/*
		This handles loading the window
		@param mBar
			This is the menu bar of Eves. This will contain file, edit, and about.
		@param w
			This is the window
		@param vbox
			Not to sure why this is needed. I think this is for locating where something goes.
	*/
	void loadWindow(Eves::Menubar *mBar, GtkWidget **w, GtkWidget **vbox)
	{
		*w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(*w), "Eves");
		gtk_window_set_default_size(GTK_WINDOW(*w),800, 600);
		gtk_window_set_position(GTK_WINDOW(*w), GTK_WIN_POS_CENTER);

		*vbox = gtk_vbox_new(FALSE, 0);
		gtk_container_add(GTK_CONTAINER(*w), *vbox);
		
		mBar->setMenuBar(gtk_menu_bar_new());
		mBar->setFileMenu(gtk_menu_new());
		mBar->setFile(gtk_menu_item_new_with_label("File"));
		mBar->setQuit(gtk_menu_item_new_with_label("Quit"));

		gtk_menu_item_set_submenu(GTK_MENU_ITEM(mBar->getFile()), mBar->getFileMenu());
		gtk_menu_shell_append(GTK_MENU_SHELL(mBar->getFileMenu()), mBar->getQuit());
		gtk_menu_shell_append(GTK_MENU_SHELL(mBar->getMenuBar()), mBar->getFile());
		gtk_box_pack_start(GTK_BOX(*vbox), mBar->getMenuBar(), FALSE, FALSE, 3);

		g_signal_connect_swapped(G_OBJECT(*w), "destroy", G_CALLBACK(gtk_main_quit), NULL);
		g_signal_connect_swapped(G_OBJECT(mBar->getQuit()), "activate", G_CALLBACK(gtk_main_quit), NULL);
	}
	
	/*
		This loads the taskbar
		@param tBar
			Holds all taskbars data
		@param w
			The E.v.e.s window
		@param vbox
			Box of some sort
	*/
	void loadTaskbar(Eves::Taskbar *tBar, GtkWidget **w, GtkWidget **vbox)
	{
		tBar->setTaskbar(gtk_toolbar_new());

		gtk_toolbar_set_style(GTK_TOOLBAR(tBar->getTaskbar()), GTK_TOOLBAR_ICONS);
		gtk_container_set_border_width(GTK_CONTAINER(tBar->getTaskbar()), 2);

		tBar->setPause(gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_PAUSE));
		gtk_toolbar_insert(GTK_TOOLBAR(tBar->getTaskbar()), tBar->getPause(), -1);

		gtk_box_pack_start(GTK_BOX(*vbox), tBar->getTaskbar(), FALSE, FALSE, 5);
	}

	/*
		This function will set the drawing area for SFML
		@param w
			Gui window
		@param area
			Drawing area for SFML
		@param m
			Event mask, I think this handles mouse and keyboard events within the area
	*/
	void setDrawingArea(GtkWidget **w, GtkWidget *vbox, GtkWidget **area, GdkEventMask *m)
	{
		*area = gtk_drawing_area_new();
		gtk_container_add(GTK_CONTAINER(vbox), *area);
		*m = GDK_ALL_EVENTS_MASK;
		gtk_widget_add_events(*area, *m);
		gtk_widget_set_can_focus(*area, true);
		gtk_widget_set_size_request(*area, 600, 600);
		gtk_widget_realize(*area);
		gtk_widget_set_double_buffered(*area, false);
	}

	bool on_close(GtkWidget *w, void *App)
	{
		((sf::RenderWindow *)App)->Close();
		return true;
	}

	bool on_expose(GtkWidget *w, GdkEvent *e, void *App)
	{
		((sf::RenderWindow *)App)->Clear(sf::Color(0, 0, 0));
		((sf::RenderWindow *)App)->Display();
		gtk_widget_queue_draw(w);
		return true;
	}

	void handleScreen(GtkWidget *area, sf::RenderWindow *App)
	{
		#ifdef WINDOWS
			App->Create(GDK_WINDOW_HWND(area->window));
		#else
			App->Create(GDK_WINDOW_XID(area->window));
		#endif
		App->SetFramerateLimit(60);
		//Seg faults here
		g_signal_connect(area, "expose-event", G_CALLBACK(Eves::on_expose), (void *)App);
		g_signal_connect(area, "destroy", G_CALLBACK(Eves::on_close), (void *)App);
	}
}
