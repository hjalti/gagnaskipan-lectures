#ifndef PLAYER_H
#define PLAYER_H

#include "PositionalObject.h"
#include "WeaponCollection.h"

class Player : public PositionalObject
{
	public:
		Player(string name, Position pos, double health, double armor);
		virtual ~Player();

		bool attack_from(Player *player);
		bool is_dead();
		double get_health();
		double get_armor();

		void pick_up(Weapon *w);
		Weapon* current_weapon();
		void next_weapon();
		void prev_weapon();

	private:
		double health;
		double armor;
		WeaponCollection *weapons;
};

#endif
