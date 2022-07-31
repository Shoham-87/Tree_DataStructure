#include <bits/stdc++.h>
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
bool RoottoNode(Tree *root, int k, vector<int> &res)
{
    if (root == NULL)
        return false;
    res.push_back(root->data);
    if (root->data == k)
        return true;
    if (RoottoNode(root->left, k, res) || RoottoNode(root->right, k, res))
        return true;
    else
    {
        res.pop_back();
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> res;
    Tree *root = NULL;
    root = Insert(root);
    RoottoNode(root, 7, res);
    for (auto i : res)
        cout << i << " ";
    return 0;
}