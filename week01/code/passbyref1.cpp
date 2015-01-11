#include <iostream>
using namespace std;

// a is a pass-by-reference parameter
void fun(int& a) {
    a = 15;
    cout << "fun: " << a << endl;
}

int main() {
    int x = 3;
    cout << "main: " << x << endl;
    // In this function call a declaration void fun(int& a) becomes
    // an alias of the variable x (i.e., just another name of the
    // variable x)
    fun(x);
    cout << "main: " << x << endl;

    return 0;
}
