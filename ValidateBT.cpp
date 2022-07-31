#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val):data(val),left(NULL),right(NULL){}
};
Tree* Insert(Tree *root)
{
    int data;
    cout<<"Enter the Data -1 for null ";
    cout.flush();
    cin>>data;
    if(data==-1)
    return NULL;
    root=new Tree(data);
    cout<<"For left "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For right "<<data<<" ";
    root->right=Insert(root->right);
    return root;
}
bool ValidateBT(Tree *root)
{
    if(!root->left || !root->right) return root->left==root->right;
    return ValidateBT(root->left) && ValidateBT(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root=NULL;
    root=Insert(root);
    cout<<ValidateBT(root);
    return 0;
}