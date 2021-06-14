#include <iostream>
using namespace std;

struct Node
{
    int val;
    struct Node *left, *right;
    Node() = default;

public:
    friend void insert(Node **q, int num);
    friend Node *newNode(int data);
    friend void traverse(Node *q);
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->val = data;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

using TREE = Node;

void traverse(Node *q)
{
    if (q == nullptr)
        return;
    std::cout << q->val << std::endl;
    traverse(q->left);

    traverse(q->right);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(6);
    root->right->left->left = newNode(5);
    root->right->left->right = nullptr;
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
    cout << "\nDepth-first traversal of tree is \n" << std::endl;
    traverse(root);
    return 0;
}