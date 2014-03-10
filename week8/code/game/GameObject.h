#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <string>
#include <iostream>

using namespace std;

class GameObject
{
	public:
		GameObject();
		GameObject(string name);
		virtual ~GameObject ();

		string get_name();
		void set_name(string name);

		virtual void display();

	private:
		string name;
};

#endif
