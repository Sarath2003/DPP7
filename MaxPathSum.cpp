#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int d)
{
    Node* t = new Node;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    return t;
}

int mxPathSum(Node* root, int &maxi)
{
    if(root == NULL)
        return 0;
    int lh = max(0, mxPathSum(root->left, maxi));
    int rh = max(0, mxPathSum(root->right, maxi));
    maxi = max(maxi, root->data + lh + rh);
    return root->data + max(lh,rh);
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    int maxi = 0;
    mxPathSum(root,maxi);
    cout << maxi;
}
