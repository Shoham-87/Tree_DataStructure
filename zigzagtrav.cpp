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
void ZigZagTrav(Tree *root,vector<vector<int>>&sol)
{
    queue<Tree *> q;
    q.push(root);
    bool flag=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++)
        {
            Tree *node=q.front();
            q.pop();
            int index=(flag)?i:(size-i-1);
            temp[index]=node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        flag=!flag;
        sol.push_back(temp);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree * root=NULL;
    root=Insert(root);
    vector<vector<int>>sol;
    ZigZagTrav(root,sol);
    for(auto i:sol)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}