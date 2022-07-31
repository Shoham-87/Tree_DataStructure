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
bool isLeaf(Tree *root)
{
    return root->left == NULL && root->right==NULL;
}
void addLeft(Tree *root,vector<int>&res)
{
    Tree *cur=root->left;
    while(cur)
    {
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}
void addLeaf(Tree *root,vector<int>&res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);return;
    }
    if(root->left) addLeaf(root->left,res);
    if(root->right) addLeaf(root->right,res);
}
void addRight(Tree *root,vector<int>&res)
{
    Tree *cur=root->right;
    vector<int>temp;
    while(cur)
    {
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur=cur->right;
        else 
            cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        res.push_back(temp[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree * root=NULL;
    root=Insert(root);
    vector<int>sol;
    sol.push_back(root->data);
    addLeft(root,sol);
    addLeaf(root,sol);
    addRight(root,sol);
    for(auto i:sol)
    cout<<i<<" ";
    return 0;
}