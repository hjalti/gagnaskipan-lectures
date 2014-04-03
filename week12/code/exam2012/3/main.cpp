#include <iostream>
#include "PriorityQueue.h"
using namespace std;
int main( )
{
    PriorityQueue q;

    q.add("Joi");        // Added to the front/back of the queue
    q.add("Gudrun", 5);  // Added to the front of the queue
    q.add("Gummi", 7);   // Added to the front of the queue
    q.add("Sigga", 3);   // Added to the next to back of the queue
    q.add("Magga");      // Added to the back of the queue

    for (int i=1; i<=5; i++)
    {
        removed = q.remove();
        cout << removed << " was removed" << endl;
    }
    removed = q.remove();
    cout << removed << " was removed" << endl;
    return 0;
}
