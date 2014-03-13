#ifndef WEAPON_COLLECTION
#define WEAPON_COLLECTION

#include "Weapon.h"

class NoWeaponsException { };

class NoMoreSpaceException { };

class WeaponCollection
{
	public:
		WeaponCollection(int capacity);
		~WeaponCollection();

		void next();
		void prev();
		Weapon* current();
		void add(Weapon *w);
		bool full();

		void display();

	private:
		Weapon **weapons;
		int curr;
		int count;
		int capacity;
};

#endif
