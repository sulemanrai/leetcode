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
 void reverseList(ListNode** head) {

        ListNode * prev = NULL;
        ListNode * curr = *head;
        ListNode * Next = NULL;

        while(curr != NULL)
        {
            Next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = Next;

        }
     *head = prev;
}
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;

        ListNode * slowptr = head;
        ListNode * fastptr = head;

        while(fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode * L2 = slowptr->next;
        ListNode * temp = new ListNode(0);
        slowptr->next = NULL;

         reverseList(&L2);
         slowptr = head;
         ListNode * L1 = head;
        if(L1 == NULL || L2 == NULL)
        {
            return;
        }
        ListNode * next_of_first_list = L1->next;
        ListNode * next_of_second_list = L2->next;

        ListNode * tmp = NULL;

        if(next_of_second_list == NULL && next_of_first_list != NULL)
        {
           L1 -> next = L2;
           L2 -> next = next_of_first_list;
            return;
        }


        while(1)
        {
            if(next_of_first_list == NULL || next_of_second_list == NULL)
            {
                break;
            }
            L1->next = L2;
            L2->next = next_of_first_list;
            tmp = next_of_first_list->next;
            next_of_first_list->next = next_of_second_list;
            L1 = next_of_first_list;
            L2 = next_of_second_list;
            next_of_first_list = tmp;
            next_of_second_list = L2->next;
        }

        if(next_of_second_list == NULL && next_of_first_list != NULL)
        {
            L2->next = next_of_first_list;
        } else if(next_of_second_list != NULL && next_of_first_list == NULL)
        {
            L1->next = next_of_second_list;
        }

    }
};
