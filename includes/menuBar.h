/*
	Menubar for E.v.e.s

	@author Ben Powell
*/
#ifndef _MENUBAR_H
#define _MENUBAR_H
namespace Eves
{
	class Menubar
	{
		public:
			void setMenuBar(GtkWidget *mBar)
			{
				this->mBar = mBar;
			}
			void setFileMenu(GtkWidget *fMenu)
			{
				this->fMenu = fMenu;
			}
			void setFile(GtkWidget *file)
			{
				this->file = file;
			}
			void setSim(GtkWidget *newSim)
			{
				this->newSim = newSim;
			}
			void setQuit(GtkWidget *quit)
			{
				this->quit = quit;
			}
			void setHelpMenu(GtkWidget *helpMenu)
			{
				this->helpMenu = helpMenu;
			}
			void setHelp(GtkWidget *help)
			{
				this->help = help;
			}
			void setAbout(GtkWidget *about)
			{
				this->about = about;
			}
			GtkWidget *getMenuBar(){ return mBar; }
			GtkWidget *getFileMenu(){ return fMenu; }
			GtkWidget *getFile(){ return file; }
			GtkWidget *getSim(){ return newSim; }
			GtkWidget *getQuit(){ return quit; }
			GtkWidget *getHelpMenu(){ return helpMenu; }
			GtkWidget *getHelp(){ return help; }
			GtkWidget *getAbout(){ return about; }
		private:
			GtkWidget *mBar, *fMenu, *file, *newSim, *quit;
			GtkWidget *helpMenu, *help, *about;
	};
}
#endif
