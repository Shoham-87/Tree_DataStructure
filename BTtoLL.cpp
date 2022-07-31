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
struct Node
{
    int data;
    Node *next;
    Node(int val):data(val),next(NULL){}
};
Tree *Insert(Tree *root)
{
    int data;
    cout<<"Enter the data and -1 for NULL";
    cout.flush();
    cin>>data;
    if(data== -1)
    return NULL;
    root=new(nothrow) Tree(data);
    cout<<"For Left: "<<data<<" ";
    root->left=Insert(root->left);
    cout<<"For Right: "<<data<<" ";
    root->right=Insert(root->right);
    return root;
}
void print(Node *head)
{
    while(head->next!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data;
}
// void PreOrder(Tree *root,Node *head)
// {
//     if(root==NULL) return ;
//     head=new Node(root->data);
//     PreOrder(root->left,head->next);
//     PreOrder(root->right,head->next);
// }
void preOrder(Tree *root)
{
    stack<Tree *>st;
    st.push(root);
    Node *head=NULL;
    while(!st.empty())
    {
        Tree * nd=st.top();
        st.pop();
        if(head==NULL) head=new Node(nd->data);
        else{
            Node *temp=head;
            while(temp->next)
            temp=temp->next;
            temp->next=new Node(nd->data);
        }
        if(nd->right) st.push(nd->right);
        if(nd->left) st.push(nd->left);
    }
    // cout<<head->data<<" "<<head->next->data<<" ";
    print(head);
}
Tree *pre=NULL;
void Flatten(Tree *root)
{
    if(!root) return ;
    Flatten(root->right);
    Flatten(root->left);
    root->right=pre;
    root->left=NULL;
    pre=root;
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
    // Node *head=NULL;
    // preOrder(root);
    Flatten(root);
    BFS(root);
    // print(head);
    return 0;
}