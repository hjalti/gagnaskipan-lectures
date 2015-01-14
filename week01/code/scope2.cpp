#include <iostream>

using namespace std;

class A {
    public:
        ~A() {
            cout << "##### Calling destructor of A" << endl;
        }
};

void stuff(A a) {
    cout << "Entering stuff" << endl;
    A b = A();
    cout << "Exiting stuff" << endl;
}

int main() {
    cout << "Entering main" << endl;
    A a = A();
    {
        cout << "Entering nested scope" << endl;
        A a = A();
        cout << "Exiting nested scope" << endl;
    }
    cout << "Before calling stuff" << endl;
    stuff(a);
    cout << "After calling stuff" << endl;
    cout << "Before loop" << endl;
    for(A a = A();;) {
        cout << "Entering loop" << endl;
        break;
    }
    cout << "After loop" << endl;
    cout << "Exiting main" << endl;
}
