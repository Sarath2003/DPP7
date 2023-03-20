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

Node* lca(Node* root, int x, int y)
{
    if(root == NULL)
        return NULL;
    if(root->data==x || root->data==y)
        return root;
    Node* lh = lca(root->left, x, y);
    Node* rh = lca(root->right, x, y);
    if(lh!=NULL && rh!=NULL)
        return root;
    else if(lh!=NULL)
        return lh;
    else
        return rh;
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

    Node* res = lca(root,8,7);
    cout << res->data;
}
