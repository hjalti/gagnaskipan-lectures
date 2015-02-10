#include<iostream>

using namespace std;

int main() {
    int *arr = new int[10];
    for(int i = 5; i < 11; i++) {
        arr[i] = i;
        cout << "Assigning value to arr[" << i << "]" << endl;
    }
    for(int i = -1; i <= 10; i++) {
        int x = arr[i];
        cout << "arr[" << i << "]: " << x << endl;
    }
    delete [] arr;
    return 0;
}
