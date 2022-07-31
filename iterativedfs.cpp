#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
    Tree(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Tree *Insert(Tree *root)
{
    int data;
    cout << "Enter the Data and -1 for null ";
    cout.flush();
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Tree(data);
    cout << "For Left of " << data << " ,";
    root->left = Insert(root->left);
    cout << "For Right of " << data << " ,";
    root->right = Insert(root->right);
    return root;
}
void Preorder(Tree *root)
{
    stack<Tree *> st;
    st.push(root);
    while (!st.empty())
    {
        Tree *Node = st.top();
        st.pop();
        cout << Node->data << " ";
        if (Node->right != NULL)
            st.push(Node->right);
        if (Node->left != NULL)
            st.push(Node->left);
    }
}
void Inorder(Tree *root)
{
    stack<Tree *> st;
    Tree *Node = root;
    while (true)
    {
        // Tree *Node = st.top();
        if (Node!= NULL)
        {
            st.push(Node);
            Node=Node->left;
        }
        else
        {
            if(st.empty()) break;
            Node=st.top();
            st.pop();
            cout<<Node->data<<" ";
            Node=Node->right;
        }
    }
}
void Postorder_2st(Tree *root)
{
    stack<Tree *>st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        Tree *Node=st1.top();
        st1.pop();
        st2.push(Node);
        if(Node->left!=NULL)
        st1.push(Node->left);
        if(Node->right!=NULL)
        st2.push(Node->right);
    }
    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}
void PostOrder_1st(Tree *root)
{
    stack<Tree *>st;
    Tree *node=root;
    while(true)
    {
        if(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        else {
            if(st.empty()) break;
            Tree *temp=st.top()->right;
            if(!temp)
            {
                temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right)
                {
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }else
            node=temp;
        }
    }

}
void AllinOne(Tree *root)
{
    vector<int> pre,in,post;
    stack<pair<Tree *,int>>st;
    st.push(make_pair(root,1));
    while(!st.empty())
    {
        auto node=st.top();
        st.pop();
        if(node.second==1){
            pre.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first->left!=NULL)
            st.push({node.first->left,1});
        }
        else if(node.second==2)
        {
            in.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first->right!=NULL)
            st.push({node.first->right,1});
        }
        else{
            post.push_back(node.first->data);
        }
    }
    for(auto i:pre)
    cout<<i<<" ";
    cout<<endl;
    for(auto i:in)
    cout<<i<<" ";
    cout<<endl;
    for(auto i:post)
    cout<<i<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree *root = NULL;
    root = Insert(root);
    // Preorder(root);
    // Inorder(root);
    // Postorder_2st(root);
    // PostOrder_1st(root);
    AllinOne(root);
    return 0;
}