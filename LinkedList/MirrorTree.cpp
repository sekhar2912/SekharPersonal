#include <iostream>
#include <deque>
#include <memory>
#include <vector>
using namespace std;

class treenode
{
public:
    int val;
    struct treenode *left, *right;
    treenode() = default;

public:
    friend void insert(treenode **q, int num);
    friend void preorder(treenode *q);
    friend void postorder(treenode *q);
    friend void inorder(treenode *q);
    friend void levelorder(treenode *q);
    friend treenode* newNode(int data);
    friend treenode* invertTree(treenode* root);

};

treenode* newNode(int data)
{
    treenode* Node = new treenode();
    Node->val = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}

using TREE = treenode;
void insert(treenode **q, int num)
{
    if (*q == nullptr)
    {
        *q = new treenode;
        (*q)->val = num;
        (*q)->left = nullptr;
        (*q)->right = nullptr;
    }
    else
    {
        if (num < (*q)->val)
            insert(&((*q)->left), num);
        else
            insert(&((*q)->right), num);
    }
    return;
}

void inorder(treenode *q) // Left - Root - Right
{
    if (q != nullptr)
    {
        inorder(q->left);
        std::cout << q->val << std::endl;
        inorder(q->right);
    }
    else
        return;
}

void preorder(treenode *q) // Root-Left-Right
{
    if (q != nullptr)
    {
        std::cout << q->val << std::endl;
        preorder(q->left);
        preorder(q->right);
    }
    else
        return;
}

void postorder(treenode *q) // Left-Right-Root
{
    if (q != nullptr)
    {
        postorder(q->left);
        postorder(q->right);
        std::cout << q->val << std::endl;
    }
    else
        return;
}


treenode* invertTree(treenode* root)
{
    if(root!=NULL)
        {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->right,root->left);
        }  
        return root;    
}
int main()
{
       treenode *t = nullptr;
    for (int i = 0; i < 10; i++)
        insert(&t, i);
    postorder(t);


    std::cout<<"-----------------"<<std::endl;
    treenode *temp = invertTree(t);
    postorder(temp);
    return 0;
}