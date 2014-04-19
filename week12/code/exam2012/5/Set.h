#include<vector>

using namespace std;

template<class T>
class Set : public vector<T>
{
    public:
        void insert(T elem);
        bool contains(T elem);
};

template<class T>
void Set<T>::insert(T elem) {
    if(!contains(elem)) {
        vector<T>::push_back(elem);
    }
}

template<class T>
bool Set<T>::contains(T elem) {
    for(size_t i = 0; i < vector<T>::size(); i++) {
        if(vector<T>::at(i) == elem) {
            return true;
        }
    }
    return false;
}
