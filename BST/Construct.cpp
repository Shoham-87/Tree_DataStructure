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
Tree *Construct(int &i ,vector<int> pOrder,int &ub)
{
    if(i>=pOrder.size() || pOrder[i]>ub) return NULL;
    Tree * root=new Tree(pOrder[i++]);
    root->left=Construct(i,pOrder,root->data);
    root->right=Construct(i,pOrder,ub);
    return root;
    
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
    vector<int>v={8,5,1,7,10,12};
    int ub=INT_MAX,i=0;
    Tree *root=Construct(i,v,ub);
    // cout<<root->data;
    BFS(root);
    return 0;
}