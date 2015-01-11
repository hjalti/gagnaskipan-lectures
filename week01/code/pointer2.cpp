#include <iostream>
using namespace std;

int main() {
    int *a = new int[10];
    for(int i = 0; i < 10; i++) {
        a[i] = i;
    }
    for(int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }
    void* x = a;
    cout << "long" << endl;
    for(int i = 0; i < 5; i++) {
        cout << ((long*)x)[i] << endl;
    }
    cout << "short" << endl;
    for(int i = 0; i < 20; i++) {
        cout << ((short*)x)[i] << endl;
    }
    cout << "char" << endl;
    for(int i = 0; i < 40; i++) {
        cout << ((int)((unsigned char*)x)[i]) << endl;
    }
    double *y = (double*)a;
    cout << "double" << endl;
    for(int i = 0; i < 5; i++) {
        cout << y[i] << endl;
    }
    return 0;
}
