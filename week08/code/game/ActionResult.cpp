#include "ActionResult.h"

ActionResult::ActionResult(bool success, string msg)
{
	this->success = success;
	this->msg = msg;
}

bool ActionResult::successful()
{
	return success;
}

string ActionResult::message()
{
	return msg;
}

WeaponActionResult::WeaponActionResult(bool success, string msg, double damage)
	: ActionResult(success, msg)
{
	this->damage = damage;
}

double WeaponActionResult::get_damage()
{
	return damage;
}
