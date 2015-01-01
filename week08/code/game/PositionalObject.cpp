#include <cmath>
#include "PositionalObject.h"

Position::Position(double x, double y)
{
	this->x = x;
	this->y = y;
}

PositionalObject::PositionalObject(string name, Position pos)
	: GameObject(name), pos(pos)
{

}

PositionalObject::~PositionalObject()
{

}

void PositionalObject::set_position(Position pos)
{
	this->pos = pos;
}

Position PositionalObject::get_position()
{
	return pos;
}

double PositionalObject::distance_to(PositionalObject *p)
{
	return sqrt(pow(pos.x - p->get_position().x, 2) + pow(pos.y - p->get_position().y, 2));
}

void PositionalObject::display()
{
	GameObject::display();
	cout <<  " at (" << pos.x << ", " << pos.y << ")";
}
