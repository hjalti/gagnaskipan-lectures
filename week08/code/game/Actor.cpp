#include <cstdlib>
#include <climits>
#include <sstream>

#include "Actor.h"

using namespace std;

Actor::Actor(string name, Position pos, double health, double armor, bool ai, double reach)
	: PositionalObject(name, pos)
{
	this->health = health;
	this->armor = armor;
	this->reach = reach;
	weapons = new WeaponCollection(10);
	weapons->add(new Weapon("Knife", 1, 1, 30));
	if(ai) {
		update_behavior = new AiActorBehavior(this);
	} else {
		update_behavior = new InteractiveActorBehavior(this);
	}
}

Actor::~Actor()
{
	delete weapons;
	delete update_behavior;
}

ActionResult Actor::attack(Actor *player)
{
	Weapon *w = weapons->current();
	double dist = distance_to(player);
	stringstream ss;
	if(dist <= w->get_range()) {
		WeaponActionResult res = w->use();
		player->deal_damage(res.get_damage());
		return res;
	} else {
		ss << player->get_name() << " is out of range of " << w->get_name() << ".";
		return ActionResult(false, ss.str());
	}
	return ActionResult(false, "");
}

bool Actor::is_dead()
{
	return health <= 0;
}

double Actor::get_health()
{
	return health;
}

double Actor::get_armor()
{
	return armor;
}

double Actor::get_reach()
{
	return reach;
}

void Actor::add_armor(double armor)
{
	this->armor = min(100.0, this->armor + armor);
}

void Actor::deal_damage(double damage)
{
	if(armor < damage) {
		damage -= armor;
		armor = 0;
	} else {
		armor -= damage;
		damage = 0;
	}
	health -= damage;
}

ActionResult Actor::pick_up(Weapon *w)
{
	stringstream ss;
	if(can_add_weapon()) {
		weapons->add(w);
		ss << "Picked up " << w->get_name() << ".";
		return ActionResult(true, ss.str());
	} else {
		ss << "Could not pick up " << w->get_name() << ". Cannot carry more weapons.";
		return ActionResult(false, ss.str());
	}
}

bool Actor::can_add_weapon()
{
	return !weapons->full();
}

Weapon* Actor::current_weapon()
{
	return weapons->current();
}

void Actor::next_weapon()
{
	weapons->next();
}

void Actor::prev_weapon()
{
	weapons->prev();
}

void Actor::update()
{
	update_behavior->update();
}

void Actor::display()
{
	PositionalObject::display();
	cout << " H: " << health << ", A: " << armor;
	if(is_dead()) {
		cout << " [DEAD]";
	}
	cout << endl;
	cout << "  Weapons:" << endl;
	weapons->display();
}
