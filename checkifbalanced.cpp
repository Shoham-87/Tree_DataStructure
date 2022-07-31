#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree {
    int data;
    Tree *left;
    Tree *right;
    Tree(int val):data(val),left(NULL),right(NULL){}
};
Tree *Insert(Tree *root)
{
    int data;
    cout<<"Enter the data and -1 for NULL";
    cout.flush();
    cin>>data;
    if(data== -1)
    return NULL;
    root=new(nothrow) Tree(data);
    cout<<"For Left: "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For Right: "<<data<<" ";
    root->right=Insert(root->right);
    return root;
}
int checkbalanced(Tree *root)
{
    if(root==NULL)return 0;
    int LB=checkbalanced(root->left);
    if(LB==-1) return -1;
    int RB=checkbalanced(root->right);
    if(RB==-1) return -1;
    if(abs(LB-RB) > 1) return -1;
    return 1+max(LB,RB);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root=NULL;
    root=Insert(root);
    cout<<checkbalanced(root);
    return 0;
}