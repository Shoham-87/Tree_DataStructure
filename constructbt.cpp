#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree {
    int data;
    Tree *left;
    Tree *right;
    Tree(int val):data(val),left(NULL),right(NULL){}
};
Tree *buildTreePostINN(vector<int>&post,int postStart,int postEnd,vector<int>&in,int inStart,int inEnd,map<int,int>&mp)
{
    if(postStart>postEnd || inStart>inEnd) return NULL;
    Tree *root=new Tree(post[postEnd]);
    int RootIndex=mp[root->data];
    int noOfNodes=RootIndex-inStart;
    root->left=buildTreePostINN(post,postStart,postStart+noOfNodes-1,in,inStart,RootIndex-1,mp);
    root->right=buildTreePostINN(post,postStart+noOfNodes,postEnd-1,in,RootIndex+1,inEnd,mp);
    return root;
}
Tree *buildTreePostIN(vector<int>&post,vector<int>&in)
{
    map<int,int>mp;
    for(int i=0;i<in.size();i++)
        mp[in[i]]=i;
    return buildTreePostINN(post,0,post.size()-1,in,0,in.size()-1,mp);

}
Tree * buildTreePreINN(vector<int>preorder,int preStart,int preEnd,vector<int>inorder,int inStart,int inEnd,unordered_map<int,int>&mp)
{
    if(preStart>preEnd || inStart>inEnd) return NULL;
    Tree* root=new Tree(preorder[preStart]);
    int Rootindex=mp[root->data];
    int noofnode=Rootindex-inStart;
    root->left=buildTreePreINN(preorder,preStart+1,preStart+ noofnode,inorder,inStart,Rootindex-1,mp);
    root->right=buildTreePreINN(preorder,preStart+noofnode+1,preEnd,inorder,Rootindex+1,inEnd,mp);
    return root;
}
Tree * buildTreePreIN(vector<int>&preorder,vector<int>&inorder)
{
    unordered_map<int,int>mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    return buildTreePreINN(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
}
void BFS(Tree *root)
{
    queue<Tree *>q;
    int n=0;
    q.push(root);
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<int>pre={3,9,20,15,7},in={9,3,15,20,7};
    vector<int> post={40,50,20,60,30,10},in={40,20,50,10,60,30};
    Tree* root=NULL;
    root=buildTreePostIN(post,in);
    BFS(root);
    return 0;
}