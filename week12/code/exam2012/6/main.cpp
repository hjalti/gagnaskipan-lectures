#include <iostream>

using namespace std;

#include "HashTable.h"
#include "HashTable.cpp"

int main()
{
    HashTable<string> a;
    string s1 = "aaaa";
    string s2 = "abaa";
    string s3 = "aaba";
    a.insert("asdf", s1);
    a.insert("adf", s2);
    a.insert("df", s3);
    cout << *a.find("asdf") << endl;
    cout << *a.find("adf") << endl;
    cout << *a.find("df") << endl;
}
