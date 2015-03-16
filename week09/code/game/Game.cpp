#include "Game.h"

#include <sstream>

using namespace std;

Game::Game()
{
	init();
}

Game::~Game()
{
	delete player;
	for(size_t i = 0; i < enemies.size(); i++) {
		delete enemies[i];
	}

	for(size_t i = 0; i < treasures.size(); i++) {
		delete treasures[i];
	}
}

void Game::init()
{
	player = new Actor("Revenant", Position(0.0, 0.0), 100.0, 100.0);
    player->set_update_behavior(new InteractiveActorBehavior(player));
	enemies.push_back(new Actor("Enemy 1", Position(1.0, 3.0), 100.0, 100.0));
	enemies.push_back(new Actor("Enemy 2", Position(8.0, 2.0), 100.0, 100.0));
	enemies.push_back(new Actor("Enemy 3", Position(8.0, 2.0), 100.0, 100.0));
	enemies.push_back(new Actor("Enemy 4", Position(9.0, 1.0), 100.0, 100.0));
	treasures.push_back(new	WeaponTreasure("Treasure 1", Position(1.0, 1.0),
				new Gun("BFG", 100.0, 0.7, 60.0, 500)));
	treasures.push_back(new	WeaponTreasure("Treasure 2", Position(-1.0, -1.0),
				new Weapon("Banana", 1.0, 0.7, 1.0)));
	treasures.push_back(new	ArmorTreasure("Treasure 3", Position(1.0, -1.0), 50.0));

	for(size_t i = 0; i < enemies.size(); i++) {
		updatable_items.push_back(enemies[i]);
	}

	for(size_t i = 0; i < treasures.size(); i++) {
		updatable_items.push_back(treasures[i]);
	}
}

ActionResult Game::move()
{
	stringstream ss;
	player->update();
	Position p = player->get_position();
	ss << player->get_name() << " moved to (" << p.x << ", " << p.y << ")";
	return ActionResult(true, ss.str());
}

ActionResult Game::pick_up_treasure(int i)
{
	stringstream ss;
	if(i < 0 || i >= static_cast<int>(treasures.size())) {
		return ActionResult(false, "No such treasure.");
	}
	Treasure *t = treasures[i];
	if(player->distance_to(t) <= player->get_reach()) {
		treasures.erase(treasures.begin() + i);
		return t->add_to(player);
	} else {
		ss << t->get_name() << " is out of reach.";
		return ActionResult(false, ss.str());
	}
}

ActionResult Game::attack(int i)
{
	stringstream ss;
	if(i < 0 || i >= static_cast<int>(enemies.size())) {
		return ActionResult(false, "No such enemy.");
	}
	Actor *enemy = enemies[i];
	return player->attack(enemy);
}

void Game::next_weapon()
{
	player->next_weapon();
}

void Game::prev_weapon()
{
	player->prev_weapon();
}

void Game::display()
{
	cout << "-------------------------------------------" << endl;
	cout << "Player: ";
	player->display();
	cout << endl;

	cout << "Enemies:" << endl;
	for(size_t i = 0; i < enemies.size(); i++) {
		cout << i << ": ";
		enemies[i]->display();
		cout << endl;
	}

	cout << "Treasures:" << endl;
	for(size_t i = 0; i < treasures.size(); i++) {
		cout << i << ": ";
		treasures[i]->display();
		cout << endl;
	}
	cout << "-------------------------------------------" << endl;
}

void Game::update()
{
	cout << updatable_items.size() << endl;
	for(size_t i = 0; i < updatable_items.size(); i++) {
		updatable_items[i]->update();
	}
}
