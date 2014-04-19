#include <iostream>
#include <vector>

using namespace std;

template<class T>
bool member(T c, vector<T> v) {
    for(size_t i = 0; i < v.size(); i++) {
        if(v[i] == c) {
            return true;
        }
    }
    return false;
}

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
