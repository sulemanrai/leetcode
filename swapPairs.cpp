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
    ListNode* swapPairs(ListNode* head) {
       if(head == NULL) {
        return NULL;
       }

        if(head->next == NULL)
            return head;

        ListNode * prev = head;
        ListNode * curr = prev->next;

        if(curr->next == NULL)
        {
            curr->next = prev;
            prev->next = NULL;
            return curr;
        }

        ListNode * tmp = curr->next;
        head = prev->next;

        while(prev->next != NULL)
        {
                curr->next = prev;
                if(tmp == NULL || tmp->next == NULL)
                {
                  prev ->next = tmp;
                    break;
                } else {
                    prev->next = tmp->next;
                }
            curr = tmp->next;
            prev = tmp;
            tmp = curr->next;
        }
        return head;
    }
};
