#include <iostream>
using namespace std;

int* init_arr(int n) {
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    return arr;
}

int main() {
    int *x = init_arr(10);
    for(int i = 0; i < 10; i++) {
        cout << x[i] << " ";
    }
    delete [] x;
    return 0;
}
