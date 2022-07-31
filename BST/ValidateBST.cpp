#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val):data(val){
        left=right=NULL;
    }
};
Tree *Insert(Tree *root)
{
    int data;
    cout<<"Enter the Data(-1 for Null)";
    cout.flush();
    cin>>data;
    if(data==-1)
    return NULL;
    root=new Tree(data);
    cout<<"For Left "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For Right "<<data<<" ";
    root->right=Insert(root->right);
    return root;
}
bool Validate(Tree *root,int IMax,int IMin)
{
    if(!root) return 1;
    if(root->data >=IMax || root->data<=IMin) return false;
    return Validate(root->left,root->data,IMin) && Validate(root->right,IMax,root->data);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root;
    root=Insert(root);
    cout<<Validate(root,INT_MAX,INT_MIN);
    return 0;
}