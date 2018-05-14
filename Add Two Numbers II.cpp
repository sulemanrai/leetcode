/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void swapPointers(ListNode ** l1, ListNode **l2)
    {
        ListNode * tmp = *l1;
        *l1 = *l2;
        *l2 = tmp;
    }

    int Size(ListNode* head)
    {
        ListNode *tmp = head;
        int count = 0;
        while(tmp != NULL)
        {
            tmp = tmp -> next;
            count++;
        }
        return count;
    }
    ListNode* addTwoNumberswithCarry(ListNode* l1, ListNode* l2, int *carry) {

            if(l1 == NULL && l2 == NULL)
                return NULL;

        ListNode* tmp =   addTwoNumberswithCarry(l1->next,l2->next,carry);
                          int sum = 0;
            if(carry != 0) {
              sum = l1->val + l2->val + *carry;
              *carry = 0;
            } else {
                sum = l1->val + l2->val;
            }
                *carry = sum / 10;
                sum = sum % 10;
            l1->val = sum;
       if(*carry == 1)
       {
           ListNode* head = new ListNode(*carry);
           head->next = l1;
           return head;
       } else {
           return l1;
       }
    }
    void Print(ListNode*head)
    {
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            cout << " " << tmp->val << endl;
            tmp = tmp->next;
        }
    }
    void makeListEqual(ListNode**head, int count)
    {
        int i = 0;
        ListNode* tmp = NULL;
        while(i != count)
        {
            tmp = new ListNode(0);
            tmp->next = *head;
            *head = tmp;
            i++;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(l1 == NULL && l2 == NULL)
            return NULL;

        if(l1 == NULL && l2 != NULL)
            return l2;

        if(l2 == NULL && l1 != NULL)
            return l1;

       int  List1Size = Size(l1);
       int  List2Size = Size(l2);
       ListNode* tmp = NULL;
       int  carry = 0;
        if(List1Size == List2Size)
        {
            tmp = addTwoNumberswithCarry(l1,l2,&carry);
        } else if(List1Size > List2Size)
        {
            int diff = List1Size - List2Size ;
            makeListEqual(&l2,diff);
            tmp = addTwoNumberswithCarry(l1,l2,&carry);
        } else if (List2Size > List1Size)
        {
            int diff = List2Size - List1Size ;
            makeListEqual(&l1,diff);
            tmp = addTwoNumberswithCarry(l1,l2,&carry);
        }

        return tmp;
    }
};
