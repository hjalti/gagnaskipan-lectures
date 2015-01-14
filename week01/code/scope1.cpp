#include <iostream>

using namespace std;

int stuff(int x) {
    cout << x << endl;
}

int main() {
    int x = 3;
    cout << x << endl;
    {
        int x = 12;
        cout << x << endl;
    }
    cout << x << endl;
    stuff(42);
    for(int x = 1337; x < 1338; x++) {
        cout << x << endl;
    }
    cout << x << endl;
}
