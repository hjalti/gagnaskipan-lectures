#include <iostream>
#include <string>

using namespace std;

#include "BstMap.h"

int main()
{
    Map<string, int>* map = new BstMap<string, int>();
    string s;
    while(cin >> s) {
        (*map)[s]++;
    }
    Map<string, int>::Iterator *it = map->get_iterator();
    while(it->has_next()) {
        Pair<string, int> p = it->next();
        cout << p.first << " " << p.second << endl;
    }
    delete it;
    delete map;

    return 0;
}
