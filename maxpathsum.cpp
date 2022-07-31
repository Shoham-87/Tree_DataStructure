#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree{
    int data;
    Tree* left;
    Tree* right;
    Tree(int val):data(val),left(NULL),right(NULL){}
};
Tree *Insert(Tree* root)
{
    int data;
    cout<<"Enter the Data and -1 for NULL ";
    cout.flush();
    cin>>data;
    if(data==-1)return NULL;
    root=new Tree(data);
    cout<<"For Left of "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For Right of "<<data<<" ";
    root->right=Insert(root->right);
    return root;
}
int maxPath(Tree*root,int &maxi)
{
    if(root==NULL) return 0;
    int LP=max(0,maxPath(root->left,maxi));
    int RP=max(0,maxPath(root->right,maxi));
    maxi=max(maxi,LP+RP+root->data);
    return max(LP,RP)+root->data;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root=NULL;
    root=Insert(root);
    int maxi=0;
    maxPath(root,maxi);
    cout<<maxi;
    return 0;
}