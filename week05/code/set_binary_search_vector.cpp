#include <iostream>
#include <vector>
#include <cstdlib>

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
        bool item_present(int index, int item);
};

IntSet::IntSet() { }

int IntSet::size() {
    return vec.size();
}

bool IntSet::empty() {
    return size() == 0;
}

// Returns true if and only if 'item' is present at 'index' in vector.
bool IntSet::item_present(int index, int item) {
    return index != size() && vec[index] == item;
}

// Returns the index before which 'item' should be inserted, in order to
// maintain the strict increasing order of vec.
// If 'item' is in vec, then the index of 'item' is returned.
int IntSet::insertion_index(int item) {
    int l = 0;
    int r = vec.size() - 1;
    int m;

    while(l <= r) {
        m = (l + r) / 2;
        if(vec[m] == item) {
            return m;
        } else if (vec[m] < item) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

bool IntSet::contains(int item) {
    int ind = insertion_index(item);
    return item_present(ind, item);
}

void IntSet::insert(int item) {
    int ind = insertion_index(item);
    if(!item_present(ind, item)) {
        vec.insert(vec.begin() + ind, item);
    }
}

void IntSet::remove(int item) {
    int ind = insertion_index(item);
    if(item_present(ind, item)) {
        vec.erase(vec.begin() + ind);
    }
}


int main() {
    srand(1337);

    IntSet s;
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
