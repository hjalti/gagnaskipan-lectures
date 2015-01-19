#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class WeirdException {
    public:
        string message;
};

void fun3() {
    WeirdException ex = { "Wat" };
    throw ex;
}

void fun2() {
    fun3();
}

void fun1() {
    fun2();
}

int main() {

    try {
        fun1();
    }
    catch (WeirdException ex) {
        cout << "Caught WeirdException(" << ex.message << ")" << endl;
    }

    return 0;
}
