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
    void Print(ListNode*head)
    {
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            cout << " " << tmp->val << endl;
            tmp = tmp->next;
        }
    }
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode * newoddHead = new ListNode(0);
        ListNode * newevenHead = new ListNode(0);
        newoddHead->next = oddHead;
        newevenHead->next = evenHead;
        int i = 0;
        while(oddHead->next != NULL && evenHead->next != NULL)
        {
             oddHead->next = evenHead->next;
             oddHead = evenHead->next;
            evenHead->next = oddHead->next;
            evenHead = oddHead->next;
        }
        newoddHead = newoddHead->next;
        newevenHead = newevenHead->next;
        oddHead->next = newevenHead;



        return newoddHead;
    }
};
