#include <iostream>
#include <string.h>
typedef struct inode ListNode;
using namespace std;

class inode
{
public:
    int val;
    struct inode *next;

public:
    friend void append(ListNode **q, int num);
    friend void display(ListNode *q);
    friend void reverse(ListNode *f);

};

void append(ListNode **q, int num)
{
    ListNode *temp = nullptr;
    ListNode *nnode = nullptr;

    if (*q == nullptr)
    {
        temp = new ListNode;
        temp->val = num;
        temp->next = nullptr;
        *q = temp;
    }
    else
    {
        temp = *q;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        nnode = new ListNode;
        nnode->val = num;
        nnode->next = nullptr;
        temp->next = nnode;
    }
}

void display(ListNode *q)
{
    std::cout << "Printing the List" <<std::endl;
    while(q!= nullptr)
    {
        std::cout << q->val << std::endl;
        q = q->next;
    }

}


void reverse(ListNode *q)
{
ListNode *current = q;
ListNode *prev{nullptr} , *next{nullptr};

while(current != nullptr)
{
    next = current->next;
    current ->next = prev;
    prev = current;
    current = next;
}
q = prev;

display(q);
}
int main()
{
    ListNode *fst = nullptr;
    append(&fst, 1);
    append(&fst, 2);
    append(&fst, 3);
    append(&fst, 4);
    append(&fst, 5);
    append(&fst, 6);
    display(fst);
    reverse(fst);
    

    return 0;
}