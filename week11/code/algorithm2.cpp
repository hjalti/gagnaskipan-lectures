#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

string to_lower(const string& s) {
    string lower;
    transform(s.begin(), s.end(), back_inserter(lower), ::tolower);
    return lower;
}

string strip(const string& s) {
    string stripped;
    remove_copy_if(s.begin(), s.end(), back_inserter(stripped), ::isspace);
    return stripped;
}


int main()
{
    string s = "HELLOOOOOO";
    cout << s << endl;
    cout << to_lower(s) << endl;

    string s2 = "this a              string has aa      lot \t\t\t of spa        ces";
    cout << s2 << endl;
    cout << strip(s2) << endl;


    return 0;
}
