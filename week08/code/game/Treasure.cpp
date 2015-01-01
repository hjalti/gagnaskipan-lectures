#include "Treasure.h"
#include <sstream>
#include <cstdlib>

using namespace std;

Treasure::Treasure(string name, Position pos)
	: PositionalObject(name, pos)
{

}

WeaponTreasure::WeaponTreasure(string name, Position pos, Weapon* weapon)
	: Treasure(name, pos)
{
	this->weapon = weapon;
}

ActionResult WeaponTreasure::add_to(Actor* player)
{
	return player->pick_up(weapon);
}

void WeaponTreasure::display()
{
	Treasure::display();
	cout << "\n\t";
	weapon->display();
}

ArmorTreasure::ArmorTreasure(string name, Position pos, double armor)
	: Treasure(name, pos)
{
	this->armor = armor;
}

ActionResult ArmorTreasure::add_to(Actor* player)
{
	player->add_armor(armor);
	stringstream ss;
	ss << "Picked up " << armor << " armor.";
	return ActionResult(true, ss.str());
}

void ArmorTreasure::update()
{
	if(armor > 0 && rand() % 100 < 10) {
		armor = max(0.0, armor - 1);
	}
}

void ArmorTreasure::display()
{
	Treasure::display();
	cout << "\n\t" << armor << " armor";
}
