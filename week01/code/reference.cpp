#include <iostream>
using namespace std;

int main() {
    int b = 3;
    int &a = b;
    cout << a << " " << b << endl;
    a = 4;
    cout << a << " " << b << endl;
    b = 12;
    cout << a << " " << b << endl;
    return 0;
}
