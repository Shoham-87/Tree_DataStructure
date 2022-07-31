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
void VerticalOrder(Tree* root)
{
    queue<pair<Tree *,int>>q;
    q.push(make_pair(root,0));
    map<int,multiset<int>>mp;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        mp[node.second].insert(node.first->data);
        if(node.first->left)
            q.push(make_pair(node.first->left,node.second-1));
        if(node.first->right)
            q.push(make_pair(node.first->right,node.second+1));
    }
    for(auto i:mp)
    {
        for(auto j:i.second)
        cout<<j<<" ";
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root=NULL;
    root=Insert(root);
    VerticalOrder(root);
    return 0;
}