#include <iostream>
using namespace std;

int special(int n) {
    int *arr = new int[n];
    int sum = 0;
    arr[0] = 1;
    for(int i = 1; i < n; i++) {
        arr[i] = 0;
        for(int j = 0; j < i; j++) {
            arr[i] += arr[j];
        }
        sum += arr[i];
    }
    delete [] arr;
    return sum;

}

int main() {
    for(int i = 1; i < 12; i++) {
        cout << special(i) << endl;
    }
    return 0;
}
