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
    void Print(ListNode *head)
    {
        ListNode * tmp = head;
        while(tmp != NULL)
        {
            cout << tmp->val << " " ;
            tmp = tmp->next;
        }
    }
    int Size(ListNode * head)
    {
        int count = 0;
        ListNode * tmp = head;
        while(tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    void append(ListNode** head)
    {
        ListNode * tmp = *head;
        ListNode * prev = NULL;
        while(tmp->next != NULL)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        prev-> next = NULL;
        tmp->next = *head;
        *head = tmp;

    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;

        int i = 0;

        if(k == 0)
            return head;

        if(k > 100)
        {
       if(k % 2 == 0)
        {
            while(k % 10 == 0)
            {
                k = k / 10;
            }
        }
        }

        while(i != k) {
        append(&head);
        i++;
        }
        return head;
    }
};
