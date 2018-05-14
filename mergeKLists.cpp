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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL && l2 == NULL)
        {
            return NULL;
        }

        if(l1 == NULL)
        {
            return l2;
        }

        if(l2 == NULL)
        {
            return l1;
        }

        ListNode * sortedHead = NULL;
        ListNode * sorted = NULL;
        ListNode* List1 = l1;
        ListNode* List2 = l2;

        if(List1->val <= List2->val)
        {
            sortedHead = List1;
            List1 = List1 -> next;
        } else if(List2->val <= List1->val)
        {
            sortedHead = List2;
            List2 = List2 -> next;
        }

        sorted = sortedHead;

        while(List1 != NULL && List2 != NULL)
        {
            if(List1->val <= List2->val)
            {
                 sorted -> next = List1;
                 sorted = sorted -> next;
                 List1 = sorted -> next;
            }
            else if(List2->val <= List1->val)
            {
                sorted -> next = List2;
                sorted = sorted -> next;
                 List2 = sorted -> next;
            }
        }

        if(List1 == NULL)
        {
            sorted -> next = List2;
        }

        if(List2 == NULL)
        {
            sorted -> next = List1;
        }

         return sortedHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
        {
            return NULL;
        }

        int size = lists.size();

        int last = size - 1;
        while(last != 0)
        {
             int i = 0;
             int j = last;

            while(i < j)
            {
                lists[i] = mergeTwoLists(lists[i],lists[j]);

                 i++;j--;

                if(i>=j)
                {
                    last = j;
                }
            }
        }

        return lists[0];
    }
};
