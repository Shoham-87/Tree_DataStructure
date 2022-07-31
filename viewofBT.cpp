#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val):data(val),left(NULL),right(NULL){}
};
Tree * Insert(Tree *root)
{
    int data;
    cout<<"Enter the data (-1 for NULL) ";
    cout.flush();
    cin>>data;
    if(data==-1)
    return NULL;
    root=new Tree(data);
    cout<<"For left of "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For right of "<<data<<" ";
    root->right=Insert(root->right);
    return root;
}
void Topview(Tree *root)
{
    map<int,int>mp;
    queue<pair<Tree *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        if(mp.find(node.second)==mp.end()) mp[node.second]=node.first->data;
        if(node.first->left)
        q.push({node.first->left,node.second-1});
        if(node.first->right)
        q.push({node.first->right,node.second+1});
    }
    for(auto i:mp)
    cout<<i.second<<" ";
}
void Bottomview(Tree *root)
{
    map<int,int>mp;
    queue<pair<Tree *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        mp[node.second]=node.first->data;
        if(node.first->left)
        q.push({node.first->left,node.second-1});
        if(node.first->right)
        q.push({node.first->right,node.second+1});
    }
    for(auto i:mp)
    cout<<i.second<<" ";
}
void RightView(Tree *root,int level,vector<int>&res)
{
    if(root==NULL)
    return;
    if(level==res.size())
    res.push_back(root->data);
    RightView(root->right,level+1,res);
    RightView(root->left,level+1,res);
}
void LeftView(Tree *root,int level,vector<int>&res)
{
    if(root==NULL)
    return;
    if(level==res.size())
    res.push_back(root->data);
    LeftView(root->left,level+1,res);
    LeftView(root->right,level+1,res);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root=NULL;
    root=Insert(root);
    Topview(root);
    cout<<endl;
    Bottomview(root);
    return 0;
}