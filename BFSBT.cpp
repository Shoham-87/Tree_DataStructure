#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
Node * Insert(Node *root)
{
    int data;
    cout<<"Enter the value of data and -1 for null";
    cout.flush();
    cin>>data;
    if(data == -1)
    return NULL;
    root=new Node(data);
    cout<<"For Left of "<<data;
    root->left=Insert(root->left);
    cout<<"For Right of "<<data;
    root->right=Insert(root->right);
    return root;
}
void BFS(Node *root)
{
    queue<Node *>q;
    int n=0;
    q.push(root);
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root=NULL;
    root=Insert(root);
    BFS(root);
    return 0;
}