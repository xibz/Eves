/*
	Taskbar for E.v.e.s
	@author Ben Powell
*/
namespace Eves
{
	class Taskbar
	{
		public:
			void setTaskbar(GtkWidget *tBar){this->tBar = tBar;}
			void setPause(GtkToolItem *pause){this->pause = pause;}

			GtkWidget *getTaskbar(){return tBar;}
			GtkToolItem *getPause(){return pause;}
		private:
			GtkWidget *tBar;
			GtkToolItem *pause;
	};
}
