#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"
#include "ActionResult.h"

class Weapon : public GameObject
{
	public:
		Weapon();
		Weapon(string name, double range, double accuracy, double damage);
		virtual ~Weapon () { }

		double get_range();
		void set_range(double range);
		double get_accuracy();
		void set_accuracy(double accuracy);
		double get_damage();
		void set_damage(double damage);
		virtual WeaponActionResult use();

		virtual void display();

	private:
		double range;
		double accuracy;
		double damage;
};

class Gun : public Weapon
{
	public:
		Gun(string name, double range, double accuracy, double damage, int ammo);

		virtual WeaponActionResult use();

		virtual void display();

	private:
		int ammo;
};

#endif
