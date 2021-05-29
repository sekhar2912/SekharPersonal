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
    vector<vector<int>> levelOrder(treenode* root);
    vector<int> leftsideView(treenode* root);
    vector<int> rightsideView(treenode* root);
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

void levelorder(treenode *q)
{
    /*
     1. Read root
     2. Enque NULL
     Loop
     2. P = DeQ() the element and print 
         i) EnQ() left and right child
     3. if p == null 
        i) EnQ NULL
    */

    //std::deque<std::shared_ptr<treenode*>>tempQ;
    std::deque<treenode *> tempQ;
    std::vector<int> res;
    TREE *t = q;

    if (t != nullptr)
    {
        tempQ.push_back(q);
        tempQ.push_back(nullptr);
    }
    auto p = tempQ.front();
    int null_ctr = 2;
    while (!tempQ.empty() && null_ctr >0)
    {  
       
        p = tempQ.front();
        if(p != nullptr)
        {
        null_ctr = 2;
        std::cout << p->val << std::endl;
        res.push_back(p->val);
        if(p->left) tempQ.push_back(p->left);
        if(p->right) tempQ.push_back(p->right);
        
        }
        else
        {
            std::cout << "\n" << std::endl;
            tempQ.push_back(nullptr); 
            null_ctr --;  
        }
        tempQ.pop_front();
    }
}

vector<vector<int>> levelOrder(treenode* root) {
    using TreeNode = treenode;
       std::deque<TreeNode *> tempQ;
    std::vector<int> res;
    vector<vector<int>>final;
    TreeNode *t = root;

    if (t != nullptr)
    {
        tempQ.push_back(root);
        tempQ.push_back(nullptr);
    }
    auto p = tempQ.front();
    int null_ctr = 2;
    while (!tempQ.empty() && null_ctr >0)
    {  
       
        p = tempQ.front();
        if(p != nullptr)
        {
        null_ctr = 2;
       // std::cout << p->val << std::endl;
        res.push_back(p->val);
        if(p->left) tempQ.push_back(p->left);
        if(p->right) tempQ.push_back(p->right);
        
        }
        else
        {  if(!res.empty())
            final.push_back(res);
            res.clear();
            std::cout << "\n" << std::endl;
            tempQ.push_back(nullptr); 
            null_ctr --;  
        }
        tempQ.pop_front();
    }
        return final;
    }

 vector<int> leftsideView(treenode* root)
 {
     vector<vector<int>> resVector = levelOrder(root);
     vector<int> leftView;
     for(int i = 0; i<resVector.size();i++)
     {
        leftView.push_back(resVector.at(i)[0]);
     }
     return leftView;

 }

vector<int> rightsideView(treenode* root)
{
     vector<vector<int>> resVector = levelOrder(root);
     vector<int> rtView;
     for(int i = 0; i<resVector.size();i++)
     {
         int index = resVector.at(i).size();
        rtView.push_back(resVector.at(i)[index-1]);
     }
     return rtView;
}
int main()
{
    // treenode *t = nullptr;
    // for (int i = 0; i < 10; i++)
    //     insert(&t, i);
    // postorder(t);

    treenode *tl = nullptr;
     treenode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
   // levelorder(root);
    std::cout << "Left Side View" <<std::endl;
    std::vector<int> temp= leftsideView(root);
    for (auto & i:temp)
     std::cout<<i << std::endl;

      
       temp.clear();
     std::cout << "Right Side View" <<std::endl;
     temp= rightsideView(root);
       for (auto & i:temp)
     std::cout<<i << std::endl;
    return 0;
}