#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> myVector;
    myVector.push_back('a');
    myVector.push_back('b');
    myVector.push_back('c');
    myVector.push_back('d');
    if (member('b', myVector))
        cout << "Element b was found!" << endl;
    if (member('d', myVector))
        cout << "Element d was found!" << endl;
    if (member('e', myVector))
        cout << "Element e was found!" << endl;
}
