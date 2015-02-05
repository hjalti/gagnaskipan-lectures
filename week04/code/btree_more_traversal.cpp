#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* NodePtr;

NodePtr parse_tree() {
    char c;
    cin >> c; // Read (

    cin >> c; // Read next character

    // If the next character is ), this is the empty tree
    if(c == ')') {
        return NULL;
    }

    // Return the "borrowed" character to the input stream
    cin.putback(c);

    int node_data;
    cin >> node_data;

    NodePtr node = new TreeNode;
    node->data = node_data;
    node->left = parse_tree();
    node->right = parse_tree();

    cin >> c; // Consume the trailing )

    return node;
}

vector<int> inorder(NodePtr tree) {
    if(tree == NULL) {
        return vector<int>();
    }
    vector<int> res = inorder(tree->left);
    res.push_back(tree->data);
    vector<int> right = inorder(tree->right);
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

void inorder2(NodePtr tree, vector<int>& res) {
    if(tree == NULL) {
        return;
    }
    inorder2(tree->left, res);
    res.push_back(tree->data);
    inorde2(tree->right, res);
    return;
}

void print_levelorder(NodePtr tree) {
    if(tree == NULL) {
        return;
    }
    queue<NodePtr> q;
    q.push(tree);
    while(!q.empty()) {
        NodePtr curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

void print_preorder(NodePtr tree) {
    if(tree == NULL) {
        return;
    }
    stack<NodePtr> s;
    s.push(tree);
    while(!s.empty()) {
        NodePtr curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if(curr->right != NULL) {
            s.push(curr->right);
        }
        if(curr->left != NULL) {
            s.push(curr->left);
        }
    }
    cout << endl;
}

int main() {
    NodePtr tree = parse_tree();
    print_levelorder(tree);
    print_preorder(tree);
    vector<int> ino;
    inorder2(tree, ino);
    for(int i = 0; i < (int)ino.size(); i++) {
        cout << ino[i] << " ";
    }
    cout << endl;
    return 0;
}
