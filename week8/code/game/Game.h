#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Actor.h"
#include "Treasure.h"

using namespace std;

class Game
{
	public:
		Game();
		~Game();

		void update();
		ActionResult move();
		ActionResult pick_up_treasure(int i);
		ActionResult attack(int i);
		void next_weapon();
		void prev_weapon();
		void display();

	private:
		Actor *player;
		vector<Actor*> enemies;
		vector<Treasure*> treasures;
		vector<Updatable*> updatable_items;

		void init();
};

#endif
