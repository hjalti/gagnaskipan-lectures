#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

template<class T, class U>
void print_pair(const pair<T,U> p) {
    cout << p.first << " " << p.second << endl;
}

int main()
{
    map<string, int> m;
    string input;
    while(cin >> input) {
        m[input]++;
    }
    for_each(m.begin(), m.end(), print_pair<string, int>);

    for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
