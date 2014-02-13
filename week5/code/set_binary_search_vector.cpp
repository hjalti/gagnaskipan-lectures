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

        bool empty();

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

        int insertion_index(int item);
};


IntSet::IntSet() { }

int IntSet::size()
{
    return vec.size();
}

bool IntSet::empty()
{
    return size() == 0;
}

int IntSet::insertion_index(int item)
{
    if(empty()) {
        return 0;
    }
    int l = 0;
    int r = vec.size() - 1;
    int m;

    while(l <= r)
    {
        m = (l + r) / 2;
        if(vec[m] == item)
        {
            return m;
        } else if (vec[m] < item) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << "blaa: " << m << endl;
    return m;
}

bool IntSet::contains(int item)
{
    return (!empty() && vec[insertion_index(item)] == item);
}

void IntSet::insert(int item)
{
    if(empty())
    {
        vec.push_back(item);
        return;
    }
    int ind = insertion_index(item);
    if(vec[ind] != item)
    {
        vec.insert(vec.begin() + ind, item);
    }
}

void IntSet::remove(int item)
{
    if(empty()) {
        return;
    }
    int ind = insertion_index(item);
    if(vec[ind] != item) {
        return;
    }
    vec.erase(vec.begin() + ind);
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
