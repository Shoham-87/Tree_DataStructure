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
int diameter(Tree *root,int &largest)
{
    if(root==NULL) return 0;
    int LH=diameter(root->left,largest);
    int RH=diameter(root->right,largest);
    if(LH+RH+1>=largest) largest=LH+RH+1;
    return 1+max(LH,RH);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree* root=NULL;
    root=Insert(root);
    int lagest=0;
    int n=diameter(root,lagest);
    cout<<lagest;
    return 0;
}