#ifndef POSITIONAL_OBJECT
#define POSITIONAL_OBJECT

#include "GameObject.h"

struct Position
{
	Position(double x = 0, double y = 0);
	double x;
	double y;
};

class PositionalObject : public GameObject
{
	public:
		PositionalObject(string name, Position pos);
		virtual ~PositionalObject();

		void set_position(Position pos);
		Position get_position();

		double distance_to(PositionalObject &p);

		virtual void display();

	private:
		Position pos;
};

#endif
