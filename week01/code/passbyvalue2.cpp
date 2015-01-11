#include <iostream>
using namespace std;

// *x is a pass-by-value parameter
void fun(int *x) {
    *x = 15;
    cout << "fun: " << *x << endl;
}

int main() {
    int *x = new int(3);
    cout << "main: " << *x << endl;
    fun(x);
    cout << "main: " << *x << endl;

    return 0;
}
