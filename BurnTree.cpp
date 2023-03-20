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

int burnTree(Node* node, unordered_map<Node*,Node*> &mp)
{
    int timee = 0;
    unordered_map<Node*,int> visit;
    queue<Node*> q;
    q.push(node);
    visit[node] = 1;
    while(!q.empty())
    {
        int nodeCount = q.size();
        int flag = 0;
        for(int i=0; i<nodeCount; i++)
        {
            Node* t = q.front();
            q.pop();
            if(t->left && !visit[t->left])
            {
                flag = 1;
                q.push(t->left);
                visit[t->left] = 1;
            }
            if(t->right && !visit[t->right])
            {
                flag = 1;
                q.push(t->right);
                visit[t->right] = 1;
            }
            if(mp[t] && !visit[mp[t]])
            {
                flag = 1;
                q.push(mp[t]);
                visit[mp[t]] = 1;
            }
        }
        if(flag == 1)
            timee++;
    }
    return timee;
}

Node* searchNode(Node* root, unordered_map<Node*,Node*> &mp, int target)
{
    if(root == NULL)
        return NULL;
    queue<Node*> q;
    Node* start;
    q.push(root);
    while(!q.empty())
    {
        Node* t = q.front();
        q.pop();
        if(t->data == target)
            start = t;
        if(t->left)
        {
            mp[t->left] = t;
            q.push(t->left);
        }
        if(t->right)
        {
            mp[t->right] = t;
            q.push(t->right);
        }
    }
    return start;
}

int timeToBurn(Node* root, int target)
{
    unordered_map<Node*,Node*> mp;
    Node* start = searchNode(root, mp, target);
    int timee = burnTree(start,mp);
    return timee;
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

    cout << timeToBurn(root,6);
}

