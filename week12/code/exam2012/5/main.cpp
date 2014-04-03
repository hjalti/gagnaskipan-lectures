#include <iostream>
#include "Set.cpp"

using namespace std;

int main()
{
    Set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(3);

    if (mySet.contains(2))
        cout << "Found element 2" << endl;
    if (!mySet.contains(4))
        cout << "Did not find element 4" << endl;

    // Hérna þarf að bæta við kóða sem skrifar út einstök stök mengisins með
    // því að nota ítrara

    return 0;
}
