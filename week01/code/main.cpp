#include <iostream>
#include "IntVector.h"

using namespace std;

int main()
{
    IntVector v1, v2(10);

    cout << "First vector:" << endl;
    cout << v1 << endl;

    cout << "Second vector:" << endl;
    cout << v2 << endl;

    for (int i = 0; i < v2.size(); i++)
    {
        v2[i] = i;
    }

    cout << "Second vector:" << endl;
    cout << v2 << endl;

    for (int i = 0; i < 60; i++)
    {
        v1.push_back(i); // Should result in an expansion of the vector
    }

    cout << "After adding to the first vector:" << endl;
    cout << v1 << endl;

    for(int i = 0; i < 10; i++)
    {
        v1.pop_back();
    }

    cout << "After popping elements from first vector:" << endl;
    cout << v1 << endl;

    IntVector v3(v2); // Calls the copy constructor
    cout << "Third vector:" << endl;
    cout << v3 << endl;

    cout << "Modifying second vector:" << endl;
    v2.insert(3, 1337);
    v2.remove_at(8);
    cout << v2 << endl;

    IntVector v4;
    v4 = v3; // Operator overloading: assignment

    cout << "Fourth vector:" << endl;
    cout << v4 << endl;

    v4.push_back(100);
    cout << "Fourth vector:" << endl;
    cout << v4 << endl;

    cout << "Lets finally try to access an element not in the vector: " << endl;
    try
    {
        cout << v4.at(50);
    }
    catch (IndexOutOfRangeException)
    {
        cout << "Index out of range!" << endl;
    }
    return 0;
}
