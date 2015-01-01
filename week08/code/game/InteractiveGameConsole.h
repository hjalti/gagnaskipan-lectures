#include "Game.h"

class InteractiveGameConsole
{
	public:
		InteractiveGameConsole();
		virtual ~InteractiveGameConsole();

		void start();

	private:
		Game *game;

		bool process_command(string command);
		void attack();
		void pick_up();
		void move();
		void display_result(ActionResult res);
		void next();
		void prev();

};
