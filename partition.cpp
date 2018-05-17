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
    void print(ListNode * head)
    {
        ListNode * tmp = head;

        while(tmp != NULL)
        {
            cout << ' ' << tmp->val;
            tmp = tmp->next;
        }
    }
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        ListNode * List1 = new ListNode(0);
        ListNode * List2 = new ListNode(0);
        ListNode * tmp1head = List1;
        ListNode * tmp2head = List2;
        ListNode * current = head;

        while(current != NULL)
        {
            if(current->val < x)
            {
                List1->next = new ListNode(current->val);
                List1 = List1->next;
            } else if(current->val >= x) {
                List2->next = new ListNode(current->val);
                List2 = List2->next;
            }
            current = current->next;
        }


        tmp1head = tmp1head->next;
        tmp2head = tmp2head->next;
        if(tmp1head != NULL) {
        List1->next = tmp2head;
        return tmp1head;
        } else {
            return tmp2head;
        }


    }
};
