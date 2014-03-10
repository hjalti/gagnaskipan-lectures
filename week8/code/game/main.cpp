#include <iostream>

#include "PositionalObject.h"

using namespace std;

int main()
{
	PositionalObject po("viii", Position(3,4));
	po.display();
	return 0;
}
