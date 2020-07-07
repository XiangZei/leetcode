#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v) {}
    Node() : val(0), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return root = new Node(val);
    }
    if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void insertIterator(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    Node *pre;
    while (root != NULL)
    {
        pre = root;
        if (root->val > val)
        {
            root = root->left;
        }
        else if (root->val <= val)
        {
            root = root->right;
        }
    }
    if (pre->val > val)
    {
        pre->left = new Node(val);
    }
    else
    {
        pre->right = new Node(val);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void inorderStack(Node *root)
{
    stack<Node *> sta;
    // while (root)
    // {
    //     sta.push(root);
    //     root = root->left;
    // }
    // while (!sta.empty())
    // {
    //     Node *tmp = sta.top();
    //     sta.pop();
    //     cout << tmp->val << endl;
    //     if (tmp->right != NULL)
    //     {
    //         tmp = tmp->right;
    //         while (tmp)
    //         {
    //             sta.push(tmp);
    //             tmp = tmp->left;
    //         }
    //     }
    // }
    Node *cur = root;
    while (cur || !sta.empty())
    {
        while (cur)
        {
            sta.push(cur);
            cur = cur->left;
        }
        cur = sta.top();
        sta.pop();
        cout << cur->val << endl;
        if (cur->right)
        {
            cur = cur->right;
        }
        else
        {
            cur = nullptr;
        }
    }
}

void preorderStack(Node *root)
{
    stack<Node *> sta;
    sta.push(root);
    while (!sta.empty())
    {
        Node *tmp = sta.top();
        sta.pop();
        if (tmp->right)
        {
            sta.push(tmp->right);
        }
        if (tmp->left)
        {
            sta.push(tmp->left);
        }
        cout << tmp->val << endl;
    }
}

void postorderStack(Node *root)
{
    stack<Node *> sta;
    Node *cur = root;
    Node *pre = nullptr;
    while (cur || !sta.empty())
    {
        while (cur)
        {
            sta.push(cur);
            cur = cur->left;
        }
        cur = sta.top();
        if (cur->right == nullptr || cur->right == pre)
        {
            cout << cur->val << "  ";
            sta.pop();
            pre = cur;
            cur = nullptr;
        }
        else
        {
            cur = cur->right;
        }
    }
}
/*
              3
             / \
            2   4
           /     \
          1       9
                 / \
                8  10

sta  3 2 
cur        null
pre        1
1

sta  3 
cur        null
pre        2
1 2

sta  3 
cur        4
pre        2
1 2

sta  3 4
cur        9
pre        2
1 2

sta  3 4 9 
cur        null
pre        8
1 2 8

sta  3 4 9 
cur        10
pre        8
1 2 8

sta  3 4 9 
cur        null
pre        10
1 2 8 10

sta  3 4  
cur        null
pre        9
1 2 8 10 9

sta  3   
cur        null
pre        4
1 2 8 10 9 4

sta     
cur        null
pre        3
1 2 8 10 9 4 3

*/

int main()
{
    Node *root = new Node(3);
    // insertIterator(root, 3);
    insertIterator(root, 2);
    insertIterator(root, 1);
    insertIterator(root, 4);
    insertIterator(root, 9);
    insertIterator(root, 10);
    insertIterator(root, 8);
    // inorder(root);
    inorderStack(root);
    cout << endl;
    preorderStack(root);
    cout << endl;
    postorderStack(root);
    cout << endl;
    return 0;
}
/*
pre 3 2 1 4 9 8 10
post 1 2 8 10 9 4 3
*/
/*
              3
             / \
            2   4
           /     \
          1       9
                 / \
                8  10
*/