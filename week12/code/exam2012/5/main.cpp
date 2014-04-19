#include <iostream>
#include "Set.h"

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

    for(vector<int>::iterator it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
