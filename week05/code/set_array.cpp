#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class IntSet
{
    public:
        // Contstructs a new set
        IntSet(int max_capacity);

        ~IntSet();

        // Returns the number of (distinct) elements in the set.
        int size();

        // Returns true if and only if the set contains 'item'.
        bool contains(int item);

        // Inserts 'item' into the set.
        // If 'item' is already a member of the set, this operation has no
        // effect.
        void insert(int item);

        // Removes 'item' from the set.
        // If 'item' is not a member of the set, this operation has no effect.
        void remove(int item);

    private:
        bool *array;
        int count;
};


IntSet::IntSet(int max_capacity)
{
    count = 0;
    array = new bool[max_capacity];

    for(int i = 0; i < max_capacity; i++)
    {
        array[i] = false;
    }
}

IntSet::~IntSet()
{
    delete [] array;
}

int IntSet::size()
{
    return count;
}

bool IntSet::contains(int item)
{
    return array[item];
}

void IntSet::insert(int item)
{
    array[item] = true;
}

void IntSet::remove(int item)
{
    array[item] = false;
}


int main()
{
    srand(1337);

    IntSet s(60000000);
    for(int i = 0; i != 20; i++) {
        s.insert(rand() % 30);
    }

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s.contains(i) ? "Yes" : "No") << endl;
        if (i % 2 == 0) {
            s.remove(i);
        }
    }
    cout << endl;

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s.contains(i) ? "Yes" : "No") << endl;
    }

    for(int i = 0; i != 100000; i++) {
        s.insert(rand() % 55789127);
    }

    cout << "Done inserting" << endl;

    for(int i = 0; i != 1000000; i++) {
        s.contains(i);
    }
}
