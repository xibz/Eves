/*
	Taskbar for E.v.e.s
	@author Ben Powell
*/
//Add tool hints?
namespace Eves
{
	class Taskbar
	{
		public:
			void setTaskbar(GtkWidget *tBar){this->tBar = tBar;}
			void setForward(GtkToolItem *forward){this->forward=forward;}
			void setPause(GtkToolItem *pause){this->pause = pause;}
			void setStart(GtkToolItem *start){this->start = start;}
			void setSep(GtkToolItem *sep){this->sep = gtk_separator_tool_item_new();}

			GtkWidget *getTaskbar(){return tBar;}
			GtkToolItem *getPause(){return pause;}
			GtkToolItem *getForward(){return forward;}
			GtkToolItem *getStart(){return start;}
			GtkToolItem *getSep(){return sep;}
		private:
			GtkWidget *tBar;
			GtkToolItem *forward, *pause, *start, *sep;//Throw these in an array?
	};
}
