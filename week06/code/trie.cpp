#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

int index_of(char c) {
    return tolower(c) - 'a';
}

struct TrieNode
{
    TrieNode(char key, bool present = false);

    char key;
    bool present;

    TrieNode* children[ALPHABET_SIZE];
};

TrieNode::TrieNode(char key, bool present)
{
    this->key = key;
    this->present = present;

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = NULL;
    }
}

typedef TrieNode* NodePtr;

class StringSet
{
    public:
        StringSet();

        ~StringSet();

        // Returns true if and only if 'str' is in the set.
        bool contains(string str);

        // Adds str to the set. If 'str' is present in the set, this operation has no effect.
        void insert(string str);

        // Removes 'str' from the set. If 'str' is not present in the se,t this operation has no effect.
        void remove(string str);

    private:
        NodePtr root;
};
