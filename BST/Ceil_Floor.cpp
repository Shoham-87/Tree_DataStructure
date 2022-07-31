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
    cout << "Enter the Data(-1 for Null)";
    cout.flush();
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Tree(data);
    cout << "For Left " << data << " ";
    root->left = Insert(root->left);
    cout << "For Right " << data << " ";
    root->right = Insert(root->right);
    return root;
}
void Ceil(Tree *root, int k, int &ceil)
{
    if (!root)
        return;
    if (root->data >= k)
    {
        ceil = root->data;
        Ceil(root->left, k, ceil);
    }
    else{
        Ceil(root->right, k, ceil);
    }
}
void Floor(Tree *root, int k, int &ceil)
{
    if (!root)
        return;
    if (root->data >= k)
    {
        Ceil(root->left, k, ceil);
    }
    else{
        ceil = root->data;
        Ceil(root->right, k, ceil);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root = NULL;
    root = Insert(root);
    int ceil = -1;
    Ceil(root, 11, ceil);
    cout << ceil;
    return 0;
}