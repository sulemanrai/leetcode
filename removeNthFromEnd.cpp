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
    int Size(ListNode* head)
    {
        int size = 0;
        while(head != NULL)
        {
         size++;
         head = head->next;
        }
        return size;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = Size(head);
        //cout << "size" << size << endl;
        int index = size - (n - 1);
        ListNode* prev = NULL;
        ListNode* curr = head;

       // cout << " index " << index << endl;
        int j = 1;
        if(j == index)
        {
            curr = curr -> next;
            free(head);
            return curr;
        }

        while(j != index)
            {
            prev = curr;
            curr = curr -> next;
            j++;
            }
        if(curr->next == NULL)
        {
            free(curr);
            prev -> next = NULL;
        } else {
            prev -> next = curr -> next;
            free(curr);
        }

        return head;
    }
};
