#ifndef ACTOR_H
#define ACTOR_H

#include "PositionalObject.h"
#include "WeaponCollection.h"
#include "ActionResult.h"
#include "Updatable.h"
#include "ActorUpdateBehavior.h"

const double DEFAULT_ACTOR_REACH = 4.0;

class ActorUpdateBehavior;

class Actor : public PositionalObject, public Updatable
{
	public:
		Actor(string name, Position pos, double health, double armor, double reach = DEFAULT_ACTOR_REACH);
		virtual ~Actor();

		ActionResult attack(Actor *player);
		bool is_dead();
		double get_health();
		double get_armor();
		double get_reach();

		void add_armor(double armor);
		ActionResult pick_up(Weapon *w);
		Weapon* current_weapon();
		void next_weapon();
		void prev_weapon();

		virtual void update();
		virtual void display();
        virtual void set_update_behavior(ActorUpdateBehavior* ub);

	private:
		double health;
		double armor;
		double reach;
		WeaponCollection *weapons;
		ActorUpdateBehavior *update_behavior;

		bool can_add_weapon();
		void deal_damage(double damage);
};

#endif
