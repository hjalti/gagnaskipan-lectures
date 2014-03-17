#include <iostream>
#include <vector>
#include <cstdlib>

#include "ArrayIntSet.h"
#include "BsVectorSet.h"
#include "ListSet.h"
#include "VectorSet.h"
#include "OrderedVectorSet.h"

using namespace std;


int main()
{
    srand(1337);

    //Set<int> *s = new ArrayIntSet(60000000);
    //Set<int> *s = new BsVectorSet<int>();
    //Set<double> *s = new ListSet<double>();
    Set<double> *s = new OrderedVectorSet<double>();

    for(int i = 0; i != 20; i++) {
        s->insert(rand() % 30);
    }

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s->contains(i) ? "Yes" : "No") << endl;
        if (i % 2 == 0) {
            s->remove(i);
        }
    }
    cout << endl;

    for(int i = 0; i != 30; i++) {
        cout << i << ": " << (s->contains(i) ? "Yes" : "No") << endl;
    }

    for(int i = 0; i != 100000; i++) {
        s->insert(rand() % 55789127);
    }

    cout << "Done inserting" << endl;

    for(int i = 0; i != 1000000; i++) {
        s->contains(i);
    }
}
