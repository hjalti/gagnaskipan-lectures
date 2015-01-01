#include "InteractiveGameConsole.h"

#include <string>

using namespace std;

InteractiveGameConsole::InteractiveGameConsole()
{
	game = new Game();
}

InteractiveGameConsole::~InteractiveGameConsole()
{
	delete game;
}

void InteractiveGameConsole::start()
{
	string command;
	do{
		game->update();
		game->display();
		cout << endl;
		cout << "Command> ";
		cin >> command;
	} while(process_command(command));
}

bool InteractiveGameConsole::process_command(string command)
{
	if(command == "quit") {
		return false;
	} else if (command == "attack") {
		attack();
	} else if (command == "pick_up") {
		pick_up();
	} else if (command == "next") {
		next();
	} else if (command == "prev") {
		prev();
	} else if (command == "move") {
		move();
	} else {
		cout << "Unknown command" << endl;
	}
	return true;
}

void InteractiveGameConsole::attack()
{
	int enemy;
	cin >> enemy;
	display_result(game->attack(enemy));
}

void InteractiveGameConsole::pick_up()
{
	int treasure;
	cin >> treasure;
	display_result(game->pick_up_treasure(treasure));
}

void InteractiveGameConsole::move()
{
	display_result(game->move());
}

void InteractiveGameConsole::display_result(ActionResult res)
{
	if(res.successful()) {
		cout << "Success!" << endl;
	} else {
		cout << "Failed" << endl;
	}
	cout << res.message() << endl;
}

void InteractiveGameConsole::next()
{
	game->next_weapon();
}

void InteractiveGameConsole::prev()
{
	game->prev_weapon();
}
