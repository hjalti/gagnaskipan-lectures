#ifndef TREASURE_H
#define TREASURE_H

#include "Actor.h"
#include "Weapon.h"
#include "ActionResult.h"

class Treasure : public PositionalObject, public Updatable
{
	public:
		Treasure(string name, Position pos);
		virtual ~Treasure() { }

		virtual ActionResult add_to(Actor* player) = 0;
		virtual void update() { }
};


class WeaponTreasure : public Treasure
{
	public:
		WeaponTreasure(string name, Position pos, Weapon* weapon);
		virtual ~WeaponTreasure();

		virtual ActionResult add_to(Actor* player);
		virtual void display();

	private:
		Weapon *weapon;
};

class ArmorTreasure : public Treasure
{
	public:
		ArmorTreasure(string name, Position pos, double armor);
		virtual ~ArmorTreasure() { }

		virtual ActionResult add_to(Actor* player);
		virtual void update();
		virtual void display();

	private:
		double armor;
};

#endif
