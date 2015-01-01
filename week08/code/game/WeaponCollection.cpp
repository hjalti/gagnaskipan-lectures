#include "WeaponCollection.h"

WeaponCollection::WeaponCollection(int capacity)
{
	this->capacity = capacity;
	weapons = new Weapon*[capacity];
	curr = 0;
	count = 0;
}

WeaponCollection::~WeaponCollection()
{
	for(int i = 0; i < count; i++) {
		delete weapons[i];
	}
	delete [] weapons;
}

void WeaponCollection::next()
{
	if(count == 0) {
		return;
	}
	curr = (curr + 1) % count;
}

void WeaponCollection::prev()
{
	if(count == 0) {
		return;
	}
	curr = (curr + count - 1) % count;
}

Weapon* WeaponCollection::current()
{
	if(count == 0) {
		throw NoWeaponsException();
	}
	return weapons[curr];
}

void WeaponCollection::add(Weapon *w)
{
	if(full()) {
		throw NoMoreSpaceException();
	}
	weapons[count++] = w;
}

bool WeaponCollection::full()
{
	return capacity == count;
}

void WeaponCollection::display()
{
	for(int i = 0; i < count; i++) {
		cout << "   ";
		if(i == curr) {
			cout << "*";
		} else {
			cout << " ";
		}
		weapons[i]->display();
		cout << endl;
	}
}
