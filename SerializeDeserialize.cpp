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
    cout<<"Enter the Data(-1 for NUll) ";
    cout.flush();
    cin>>data;
    if(data==-1)return NULL;
    root=new Tree(data);
    cout<<"For Left "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For Right "<<data<<" ";;
    root->right=Insert(root->right);
    return root;
}
string Serialize(Tree *root)
{
    if(root==NULL) return "";
    string ans="";
    queue<Tree *> q;
    q.push(root);
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        if(node==NULL)
        ans.append("#,");
        else
        ans.append(to_string(node->data)+',');
        if(node!=NULL)
        {
        q.push(node->left);
        q.push(node->right);
        }
    }
    return ans;
}
Tree *Deserialize(string ans)
{
    stringstream data(ans);
    string node;
    getline(data,node,',');
    Tree *root=new Tree(stoi(node));
    queue<Tree *>q;
    q.push(root);
    while(!q.empty())
    {
        Tree *Node=q.front();
        q.pop();
        getline(data,node,',');
        if(node=="#")
        Node->left=NULL;
        else
        Node->left=new Tree(stoi(node));
        getline(data,node,',');
        if(node=="#")
        Node->right=NULL;
        else
        Node->right=new Tree(stoi(node));
        if(Node->left) q.push(Node->left);
        if(Node->right) q.push(Node->right);
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
    // BFS(root);
    cout<<Serialize(root);
    Tree *rroot=Deserialize(Serialize(root));
    BFS(rroot);
    return 0;
}