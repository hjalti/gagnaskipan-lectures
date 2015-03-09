#include <cstdlib>
#include <climits>
#include <sstream>

#include "Weapon.h"

Weapon::Weapon()
	: GameObject("")
{

}

Weapon::Weapon(string name, double range, double accuracy, double damage)
	: GameObject(name)
{
	this->range = range;
	this->accuracy = accuracy;
	this->damage = damage;
}

double Weapon::get_range()
{
	return range;
}

void Weapon::set_range(double range)
{
	this->range = range;
}

double Weapon::get_accuracy()
{
	return accuracy;
}

void Weapon::set_accuracy(double accuracy)
{
	this->accuracy = accuracy;
}

double Weapon::get_damage()
{
	return damage;
}

void Weapon::set_damage(double damage)
{
	this->damage = damage;
}

void Weapon::display()
{
	GameObject::display();
	cout << ", R: " << range << ", A: " << accuracy << ", D: " << damage;
}

WeaponActionResult Weapon::use()
{
	stringstream ss;
	if(rand() / static_cast<double>(RAND_MAX) < get_accuracy()) {
		ss << "Dealt " << damage << " damage using " << get_name() << ".";
		return WeaponActionResult(true, ss.str(), damage);
	} else {
		ss << "Swing and a miss with " << get_name() << ".";
		return WeaponActionResult(false, ss.str(), 0);
	}
}

Gun::Gun(string name, double range, double accuracy, double damage, int ammo)
	: Weapon(name, range, accuracy, damage), ammo(ammo)
{

}

WeaponActionResult Gun::use()
{
	if(ammo == 0) {
		stringstream ss;
		ss << get_name() << " is out of ammo." << endl;
		return WeaponActionResult(false, ss.str(), 0.0);
	}
	ammo--;
	return Weapon::use();
}

void Gun::display()
{
	Weapon::display();
	cout << ", Ammo: " << ammo;
}
