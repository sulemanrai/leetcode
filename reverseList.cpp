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
    ListNode* reverseList(ListNode* head) {

        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * Next = NULL;

        while(curr != NULL)
        {
            Next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = Next;

        }
    return prev;

    }
};
