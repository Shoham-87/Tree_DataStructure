#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
Node* InsertNode(Node *root)
{
    int data;
    cout<<"Enter the value of Data and -1 for NUll"<<endl;
    cout.flush();
    cin>>data;
    if(data==-1)
    return NULL;
    root=new(nothrow) Node(data);
    cout<<"For Left Node "<<data<<endl;
    root->left=InsertNode(root->left);
    cout<<"For Right Node "<<data<<endl;
    root->right=InsertNode(root->right);
    return root;
    
}
void Inorder(Node *root)
{
    if (!root)
        return;
    Inorder(root->left);
    cout << root->data<<" ";
    Inorder(root->right);
}
void Preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node *root)
{
    if (!root)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root=NULL;
    root = InsertNode(root);
    Inorder(root);
    return 0;
}