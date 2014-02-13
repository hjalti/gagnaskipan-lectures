#include <iostream>
#include <vector>

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
        vector<int> vec;

        int index(int item);
};


IntSet::IntSet() { }

int IntSet::size()
{
    return vec.size();
}

int IntSet::index(int item)
{
    for(size_t i = 0; i != vec.size(); i++) {
        if(vec[i] == item) {
            return i;
        }
    }
    return -1;
}

bool IntSet::contains(int item)
{
    return (index(item) != -1);
}

void IntSet::insert(int item)
{
    vec.push_back(item);
}

void IntSet::remove(int item)
{
    int ind = index(item);
    while(ind != -1)
    {
        vec.erase(vec.begin() + ind);
        ind = index(item);
    }
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
