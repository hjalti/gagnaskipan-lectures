#ifndef UPDATABLE_H
#define UPDATABLE_H

class Updatable
{
	public:
		virtual ~Updatable() { }

		virtual void update() = 0;
};

#endif
