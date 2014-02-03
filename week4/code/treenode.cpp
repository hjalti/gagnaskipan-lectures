#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* NodePtr;

int main()
{
    NodePtr root = new TreeNode;
    root->data = 10;


    NodePtr left_child = new TreeNode;
    left_child->data = 4;

    NodePtr right_child = new TreeNode;
    right_child->data = 82;

    root->left = left_child;
    root->right = right_child;

    return 0;
}
