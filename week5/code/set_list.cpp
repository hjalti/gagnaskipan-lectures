#include <iostream>
#include <list>

using namespace std;

class IntSet
{
    public:
        // Contstructs a new set
        IntSet();

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
        list<int> lis;
};


IntSet::IntSet() { }

int IntSet::size()
{
    return lis.size();
}


bool IntSet::contains(int item)
{
    for(list<int>::iterator it = lis.begin(); it != lis.end(); ++it)
    {
        if(*it == item)
        {
            return true;
        }
    }
    return false;
}

void IntSet::insert(int item)
{
    lis.push_back(item);
}

void IntSet::remove(int item)
{
    lis.remove(item);
}


int main()
{
    IntSet s;
    for(int i = 0; i != 10; i++) {
        s.insert(i * 1337 % 29);
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
        s.insert(i * 1337 % 55789127);
    }

    cout << "Done inserting" << endl;

    for(int i = 0; i != 1000000; i++)
    {
        s.contains(i);
    }
}
