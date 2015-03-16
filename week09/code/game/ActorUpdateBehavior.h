#ifndef ACTORUPDATEBEHAVIOR_H
#define ACTORUPDATEBEHAVIOR_H

#include "Updatable.h"
#include "Actor.h"

class Actor;

class ActorUpdateBehavior
{
	public:
		ActorUpdateBehavior(Actor *actor = NULL);
		virtual ~ActorUpdateBehavior() { }

        void set_actor(Actor *actor);
		virtual void update() { }

	protected:
		Actor *actor;
};


class AiActorBehavior : public ActorUpdateBehavior
{
	public:
		AiActorBehavior(Actor *actor);
		virtual ~AiActorBehavior() { }

		virtual void update();
};

class InteractiveActorBehavior : public ActorUpdateBehavior
{
	public:
		InteractiveActorBehavior(Actor *actor);
		virtual ~InteractiveActorBehavior() { }

		virtual void update();
};

#endif
