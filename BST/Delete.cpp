#include <bits/stdc++.h>
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
Tree *Inorder_Successor(Tree **root)
{
    if ((*root)->right==NULL)
    {
        auto nd = (*root);
        (*root)=NULL;
        return nd;
    }
    return Inorder_Successor(&(*root)->right);
}
Tree *Inorder_Predecessor(Tree **root)
{
    if ((*root)->left==NULL)
    {
        auto nd = (*root);
        (*root)=NULL;
        return nd;
    }
    return Inorder_Predecessor(&(*root)->left);
}
Tree *Delete_Node(Tree *root, int k)
{
    auto cur=root;
    while(cur)
    {
        if(cur->data==k)
        {
            Tree *nd;
            if(cur->right)
                nd=Inorder_Predecessor(&cur->right);
            nd->left=cur->left;
            
            // else if(cur->left)
            //     nd=Inorder_Successor(&cur->left);
            // else
            //     cur=NULL;
            // // // nd->left=cur->left;
            // // // nd->right=cur->right;
            // cur->data=nd->data;
            // // delete cur;
            // // nd=NULL;
            // // cout<<nd->data;
            break;
        }
        else if(cur->data>k)
        cur=cur->left;
        else
        cur=cur->right;
    }
    return root;
}
void BFS(Tree *root)
{
    queue<Tree *> q;
    int n = 0;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root = NULL;
    root = Insert(root);
    // auto nd=Inorder_Successor(root);
    // BFS(root);
    // cout<<nd->data;
    root=Delete_Node(root,2);
    BFS(root);
    return 0;
}