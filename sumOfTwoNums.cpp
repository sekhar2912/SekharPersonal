#include <iostream>

/* 
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example :
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

using namespace std;


typedef struct inode ListNode;

class inode{
public:
  int val;
  struct inode *next;
public:
friend void append(ListNode **q, int num);
friend void display(ListNode *q);
friend ListNode* addTwoNumbers(ListNode *f, ListNode *s);
friend int count(ListNode *l);
};

int count(ListNode *l)
{
    int count = 0;
    while(l != nullptr)
    {
        l = l->next;
        count++;
    }
    return count;
}

ListNode* addTwoNumbers(ListNode* f, ListNode* s) {
      
   int carry{0};
   int remaining{0};
   ListNode *ret = nullptr;

   while(f != nullptr || s != nullptr)
   {
       
       auto first{0};
       auto second{0};
       if(f) first = f->val;
       if(s) second = s->val;
       int sum  = first + second + carry;
       carry = 0;

       if (sum >= 10)
       {
        carry = 1;
        remaining = sum -10;
       }
       else 
       {
           remaining = sum;
       }
           
       append(&ret,remaining);
       if(f) f = f->next;
       if(s) s = s->next;
       
   }
   if(carry) append(&ret,carry);
    return ret;
        
    }

void append(ListNode **q, int num)
{
    ListNode *temp = nullptr;
    ListNode *nnode = nullptr;

    if(*q == nullptr) // Empty List, create a new node and return
     {
        temp = new inode;
        temp->val = num;
        temp->next = nullptr;
        *q = temp;

     }
     else
     {
         // 1. Go to the end of list and append
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
    std::cout << "\n"<< std::endl;
    while(q != nullptr)
    {
        std::cout<< q->val;
        q = q->next;
    }
}

int main()
{
    ListNode *fst = nullptr;
    append(&fst, 9);
    append(&fst, 9);
    append(&fst, 9);
    append(&fst, 9);
    append(&fst, 9);
    append(&fst, 9);
    append(&fst, 9);

    display(fst);

    ListNode *Snd = nullptr;
    append(&Snd, 9);
    append(&Snd, 9);
    append(&Snd, 9);
    append(&Snd, 9);
    display(Snd);
    std::cout << "--------------------------------" << std::endl;
    ListNode *l = addTwoNumbers(fst, Snd);
    display(l);
    return 0;
}