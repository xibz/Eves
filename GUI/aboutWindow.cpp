#include <gtk/gtk.h>
#ifdef WINDOWS
#include <gdk/gdkwin32.h>
#else
#include <gdk/gdkx.h>
#endif
namespace Eves
{
	void showAbout()
	{
		//GdkPixbuf *logo = gdk_pixbuf_new_from_file("logo.png", NULL);
		GtkWidget *d = gtk_about_dialog_new();
		gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(d), "E.v.e.s");
		gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(d), "0.1");
		gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(d),
				"(c) Ben Powell");
		gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(d),
				"A simulation tool for analyzing traits");
		gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(d),
				"http://www.someweb.com");
		//gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(d), logo);
		//g_object_unref(logo), logo = NULL;
		gtk_dialog_run(GTK_DIALOG(d));
		gtk_widget_destroy(d);
	}
};
