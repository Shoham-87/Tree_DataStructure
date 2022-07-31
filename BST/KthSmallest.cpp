#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val) : data(val)
    {
        left = right = NULL;
    }
};
Tree *Insert(Tree *root)
{
    int data;
    cout << "Enter the Data(-1 for NULL)";
    cout.flush();
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Tree(data);
    cout << "For Left of" << data << " ";
    root->left = Insert(root->left);
    cout << "For Right of" << data << " ";
    root->right = Insert(root->right);
    return root;
}
void KthSmallest(Tree *root,int k,int &c,int &ans)
{
    if(!root) return;
    KthSmallest(root->left,k,c,ans);
    c+=1;
    if(c==k)ans=root->data;
    KthSmallest(root->right,k,c,ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=-1,c=0;
    Tree *root=NULL;
    root=Insert(root);
    KthSmallest(root,3,c,ans);
    cout<<ans;
    return 0;
}