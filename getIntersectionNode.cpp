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
    int Size(ListNode *head)
    {
        ListNode * tmp = head;
        int count = 0;
        while(tmp != NULL)
        {
            count++;
            tmp = tmp -> next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * tmp1 = headA;
        ListNode * tmp2 = headB;
        ListNode * intersect = NULL;

        if(headA == NULL || headB == NULL)
            return intersect;

        if(Size(headA) >= Size(headB)) {

        for(ListNode * tmp1 = headA; tmp1 != NULL; tmp1 = tmp1->next)
        {
            for(ListNode * tmp2 = headB; tmp2 != NULL; tmp2 = tmp2->next)
            {
                if(tmp1->val == tmp2->val)
                {
                    intersect = tmp1;
                   return intersect;
                }
            }
        }

        } else if (Size(headB) >= Size(headA))
        {
            for(ListNode * tmp1 = headB; tmp1 != NULL; tmp1 = tmp1->next)
        {
            for(ListNode * tmp2 = headA; tmp2 != NULL; tmp2 = tmp2->next)
            {
                if(tmp1->val == tmp2->val)
                {
                    intersect = tmp1;
                    return intersect;
                }
            }
        }
        }

        return intersect;
    }
};
