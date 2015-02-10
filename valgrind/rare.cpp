#include<iostream>

using namespace std;

int main() {
    int *brr = new int[3];
    delete brr;
    int *arr = new int[-10];
    delete [] arr;
    return 0;
}
