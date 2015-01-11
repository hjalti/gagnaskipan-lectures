#include <iostream>
using namespace std;

void fun() {
    int *x = new int[10];
    for(int i = 0; i < 10; i++) {
        x[i] = i;
    }

}

int main() {
    fun();
    return 0;
}
