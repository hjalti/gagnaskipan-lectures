#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"

class Weapon : public GameObject
{
	public:
		Weapon();
		Weapon(string name, double range, double accuracy, double damage);
		virtual ~Weapon ();

		double get_range();
		void set_range(double range);
		double get_accuracy();
		void set_accuracy(double accuracy);
		double get_damage();
		void set_damage(double damage);

	private:
		double range;
		double accuracy;
		double damage;
};

#endif
