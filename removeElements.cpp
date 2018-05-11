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
    int Size(ListNode * head)
    {
        int i = 0;
        while(head != NULL)
        {
            i++;
            head = head->next;
        }
        return i;
    }
    ListNode* removeElements(ListNode* head, int val) {
         if(head == NULL) {
            return NULL;
         }

         std::queue<int> Linked_List_queue;
        ListNode * temp = head;

        while(temp != NULL)
        {
            Linked_List_queue.push(temp->val);
            temp = temp -> next;
        }

        ListNode * newHead = new ListNode(0);
        ListNode * current = newHead;

        while(!Linked_List_queue.empty())
        {
            int tmp= Linked_List_queue.front();
            if(tmp != val)
            {
                current->next = new ListNode(tmp);
                current = current->next;
            }
            Linked_List_queue.pop();
        }

        if(newHead->next == NULL)
        {
            newHead = NULL;
        } else {
        *newHead = *newHead->next;
        }
        return newHead;
    }
};
