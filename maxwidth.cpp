#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val) : data(val), left(NULL), right(NULL){};
};
Tree *Insert(Tree *root)
{
    int data;
    cout << "Enter the Data  (-1 for NULL)";
    cout.flush();
    cin >> data;
    if (data == -1)
        return NULL;
    root = new (nothrow) Tree(data);
    cout << "For Left: " << data << " ";
    root->left = Insert(root->left);
    cout << "For Right: " << data << " ";
    root->right = Insert(root->right);
    return root;
}
int maxwidth(Tree*root)
{
    queue<pair<Tree *,int>>q;
    q.push({root,0});
    int f=0,l=0,ans=0;
    while(!q.empty())
    {
        int size=q.size();
        int mmin=q.front().second;
        for(int i=0;i<size;i++)
        {
            auto node=q.front().first;
            int cur=q.front().second-mmin;
            if(i==0) f=q.front().second;
            if(i==size-1) l=q.front().second;
            q.pop();
            if(node->left)
                q.push({node->left,2*cur+1});
            if(node->right)
                q.push({node->right,2*cur+2});
        }
        ans=max(ans,l-f+1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree*root=NULL;
    root=Insert(root);
    cout<<maxwidth(root);
    return 0;
}