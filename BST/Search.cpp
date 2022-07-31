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
Tree *Search(Tree* root,int k)
{
    if(!root) return NULL;
    if(root->data == k) return root;
    return (root->data > k) ?Search(root->left,k) : Search(root->right,k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root=NULL;
    root=Insert(root);
    Tree * val=Search(root,10);
    cout<<(val==NULL)<<" "<<val->data;
    return 0;
}