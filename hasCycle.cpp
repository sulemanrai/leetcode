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
    bool hasCycle(ListNode *head) {
        ListNode * slowptr = head;
        ListNode * fastptr = head;
        bool cycle = false;
        int i = 0;

        while(slowptr && fastptr && fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;

            if(slowptr == fastptr)
            {
                cycle = true;
                break;
            }
        }

        return cycle;
    }
};
