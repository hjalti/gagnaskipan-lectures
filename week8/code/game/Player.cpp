#include <cstdlib>
#include <climits>

#include "Player.h"

Player::Player(string name, Position pos, double health, double armor)
	: PositionalObject(name, pos)
{
	this->health = health;
	this->armor = armor;
	weapons = new WeaponCollection(10);
	weapons->add(new Weapon("Knife", 1, 1, 30));
}

Player::~Player()
{
	delete weapons;
}

bool Player::attack_from(Player *player)
{
	Weapon *w = player->current_weapon();
	double dist = distance_to(*player);
	if(dist <= w->get_range() && rand() / static_cast<double>(RAND_MAX) < w->get_accuracy()) {
		double damage = w->get_damage();
		if(armor < damage) {
			damage -= armor;
			armor = 0;
		} else {
			armor -= damage;
			return true;
		}
		health -= damage;
		return true;
	}
	return false;
}

bool Player::is_dead()
{
	return health <= 0;
}

double Player::get_health()
{
	return health;
}

double Player::get_armor()
{
	return armor;
}

void Player::pick_up(Weapon *w)
{
	weapons->add(w);
}

Weapon* Player::current_weapon()
{
	return weapons->current();
}

void Player::next_weapon()
{
	weapons->next();
}

void Player::prev_weapon()
{
	weapons->prev();
}
