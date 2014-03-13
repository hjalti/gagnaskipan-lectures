#ifndef ACTIONRESULT_H
#define ACTIONRESULT_H

#include <string>

using namespace std;

class ActionResult
{
	public:
		ActionResult(bool success, string message);
		virtual ~ActionResult() { }

		bool successful();
		string message();

	private:
		bool success;
		string msg;
};

class WeaponActionResult : public ActionResult
{
	public:
		WeaponActionResult(bool success, string message, double damage);
		virtual ~WeaponActionResult() { }

		double get_damage();

	private:
		double damage;
};

#endif
