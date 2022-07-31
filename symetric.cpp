#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val):data(val),left(NULL),right(NULL){};
};
Tree *Insert(Tree * root)
{
    int data;
    cout<<"Enter the Data  (-1 for NULL)";
    cout.flush();
    cin>>data;
    if(data==-1)
    return NULL;
    root=new(nothrow) Tree(data);
    cout<<"For Left: "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For Right: "<<data<<" ";
    root->right=Insert(root->right);
    return root;
}
bool symmetricCheck(Tree *lft,Tree* rght)
{
    if(lft==NULL || rght==NULL) return lft==rght;
    if(lft->data!=rght->data)  return false;
    return symmetricCheck(lft->left,rght->right) && symmetricCheck(lft->right,rght->left);
}
bool isSymmetric(Tree *root)
{
    if(root==NULL)
    return true;
    return symmetricCheck(root->left,root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree* root=NULL;
    root=Insert(root);
    cout<<isSymmetric(root);
    return 0;
}