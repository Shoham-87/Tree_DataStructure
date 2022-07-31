#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val):data(val),left(NULL),right(NULL){}
};
int height(Tree *root)
{
    if(root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
int height_BFS(Tree *root)
{
    queue<Tree *>q;
    int n=0;
    if(!root)
    return 0;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        n++;
        Tree * node=q.front();
        for(int i=0;i<size;i++)
        {
        q.pop();
            if(node->left!=NULL)
            q.push(node->left);
            if(node->right!=NULL)
            q.push(node->right);
        }
    }
    return n;
}
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root=NULL;
    root=Insert(root);
    cout<<height(root)<<" ";
    cout<<height_BFS(root);
    return 0;
}