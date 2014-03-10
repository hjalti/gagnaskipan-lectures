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

Weapon::~Weapon()
{

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

