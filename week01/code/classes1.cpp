#include <iostream>
#include <string>

using namespace std;

class A {
    public:
        string s;
        A(string s) {
            this->s = s;
        }
        ~A() {
            cout << "##### Calling destructor of A(" << s << ")" << endl;
        }
};

void stuff(A a) {
    cout << "Entering stuff" << endl;
    A b = A("Inside stuff");
    cout << "Exiting stuff" << endl;
}

int main() {
    cout << "Entering main" << endl;
    A a = A("In main");
    {
        cout << "Entering nested scope" << endl;
        A a = A("In nested scope");
        cout << "Exiting nested scope" << endl;
    }
    cout << "Before calling stuff" << endl;
    stuff(a);
    cout << "After calling stuff" << endl;
    cout << "Before loop" << endl;
    for(A a = A("In for loop");;) {
        cout << "Entering loop" << endl;
        break;
    }
    cout << "After loop" << endl;
    cout << "Exiting main" << endl;
}
