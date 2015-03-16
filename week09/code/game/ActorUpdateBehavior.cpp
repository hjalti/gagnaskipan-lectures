#include "ActorUpdateBehavior.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

ActorUpdateBehavior::ActorUpdateBehavior(Actor *actor)
{
	this->actor = actor;
}

void ActorUpdateBehavior::set_actor(Actor *actor)
{
    this->actor = actor;
}

AiActorBehavior::AiActorBehavior(Actor *actor)
	: ActorUpdateBehavior(actor)
{

}


void AiActorBehavior::update()
{
	Position p = actor->get_position();
	if(rand() % 100 < 10) {
		p.x--;
	}
	if(rand() % 100 < 10) {
		p.x++;
	}
	if(rand() % 100 < 10) {
		p.y--;
	}
	if(rand() % 100 < 10) {
		p.y++;
	}
	actor->set_position(p);
}

InteractiveActorBehavior::InteractiveActorBehavior(Actor *actor)
	: ActorUpdateBehavior(actor)
{

}

void InteractiveActorBehavior::update()
{
	char c;
	Position p = actor->get_position();
	while(true) {
		cout << "Enter a direction: ";
		cin >> c;
		switch(c) {
			case 'u':
				p.y++;
				break;
			case 'd':
				p.y--;
				break;
			case 'l':
				p.x--;
				break;
			case 'r':
				p.x++;
				break;
			default:
				continue;
		}
		actor->set_position(p);
		return;
	}
}
