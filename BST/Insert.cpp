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
Tree *Insert_Node(Tree *root,int data)
{
    if(!root)
    {
        return new Tree(data);
    }
    if(root->data<data)
    {
        root->right=Insert_Node(root->right,data);
    }
    else{
        root->left=Insert_Node(root->left,data);
    }
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
    Tree *root=NULL;
    root=Insert(root);
    root=Insert_Node(root,1);
    BFS(root);
    return 0;
}