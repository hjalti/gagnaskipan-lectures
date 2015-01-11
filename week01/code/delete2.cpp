#include <iostream>
using namespace std;

int sum(int *arr, int n) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;

}

int main() {
    int *x = new int[10];
    for(int i = 0; i < 10; i++) {
        x[i] = i * i;
    }
    cout << sum(x, 10) << endl;
    return 0;
}
