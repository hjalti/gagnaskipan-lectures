#include "GameObject.h"

GameObject::GameObject()
{ }

GameObject::GameObject(string name)
	: name(name)
{ }

GameObject::~GameObject ()
{

}

string GameObject::get_name()
{
	return name;
}

void GameObject::set_name(string name)
{
	this->name = name;
}


void GameObject::display()
{
	cout << name << endl;
}
