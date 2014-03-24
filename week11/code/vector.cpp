#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 100; i++) {
        v.push_back(i * i);
    }
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        (*it)++;
    }

    cout << endl;
    cout << endl;

    for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v2;

    int i = 0;
    while(v2 != v) {
        v2.push_back(i * i + 1);
        i++;
    }

    cout << (v == v2) << endl;

    return 0;
}
