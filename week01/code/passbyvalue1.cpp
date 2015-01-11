#include <iostream>
using namespace std;

void fun(int x) { // x is a pass-by-value parameter
    x = 15;
    cout << "fun: " << x << endl;
}
int main() {
    int x = 3;
    cout << "main: " << x << endl;
    fun(x);
    cout << "main: " << x << endl;
    return 0;
}
