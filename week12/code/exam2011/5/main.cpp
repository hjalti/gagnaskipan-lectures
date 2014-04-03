#include <iostream>
#include "IntPair.h"
using namespace std;
int main()
{
    IntPair p1(20, 45);
    IntPair p2(10, 20);
    IntPair* newPair;
    newPair = p1 + p2;
    // The result should be (30, 65)
    cout << "Result: (" << newPair->first << ", "
        << newPair->second << ")" << endl;
}
