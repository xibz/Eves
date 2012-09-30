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
			void setQuit(GtkWidget *quit)
			{
				this->quit = quit;
			}
			GtkWidget *getMenuBar(){ return mBar; }
			GtkWidget *getFileMenu(){ return fMenu; }
			GtkWidget *getFile(){ return file; }
			GtkWidget *getQuit(){ return quit; }
		private:
			GtkWidget *mBar, *fMenu, *file, *quit;
	};
}
#endif
