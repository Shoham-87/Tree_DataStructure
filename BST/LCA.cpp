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
    cout<<"Enter the Data(-1 for NULL)";
    cout.flush();
    cin>>data;
    if(data==-1) return NULL;
    root=new Tree(data);
    cout<<"For Left of" <<data<<" ";
    root->left=Insert(root->left);
    cout<<"For Right of" <<data<<" ";
    root->right=Insert(root->right);
    return root;
}
Tree * LCA(Tree *root,int l,int r)
{
    if(!root) return NULL;
    if(root->data > l && root->data >r) return LCA(root->left,l,r);
    if(root->data < l && root->data <r) return LCA(root->right,l,r);
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}