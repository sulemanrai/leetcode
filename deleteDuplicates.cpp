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
    void print_queue(std::queue<int> q)
    {
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;


        std::queue<int> Linked_List_queue;
        ListNode * temp = head;

        while(temp != NULL)
        {
            Linked_List_queue.push(temp->val);
            temp = temp -> next;
        }

        //print_queue(Linked_List_queue);
        //Linked_List_queue.pop();
        print_queue(Linked_List_queue);

        int tmp= Linked_List_queue.front();
        Linked_List_queue.pop();
       // cout << " tmp " << tmp << endl;
        ListNode * newHead = new ListNode(tmp);
        ListNode * current = newHead;

        // print_queue(Linked_List_queue);
        while(!Linked_List_queue.empty())
        {
            int tmp= Linked_List_queue.front();
            if(current->val != tmp)
            {
                current->next = new ListNode(tmp);
                current = current->next;
            }
            Linked_List_queue.pop();
        }

         return newHead;
    }


};
