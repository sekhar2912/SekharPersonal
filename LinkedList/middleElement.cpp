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
    while(q->next != nullptr)
    {
        std::cout << q->val << std::endl;
        q = q->next;
    }

}

int getMiddileNode(ListNode *q)
{
    ListNode *slow_ptr = q;
    ListNode *fast_ptr = q;
    if(q == nullptr) 
    {
        std::cout << "Encountered Empty list" << std::endl;
        exit(0);
    }
    else
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            cout << "The middle element is [" << slow_ptr->val << "]" << endl;
    }


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

    getMiddileNode(fst);

    return 0;
}