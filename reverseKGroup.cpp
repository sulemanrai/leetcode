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

    void Print(ListNode *head)
    {
        ListNode * tmp = head;
        while(tmp != NULL)
        {
            cout << tmp->val << " " ;
            tmp = tmp->next;
        }
    }

    int Size(ListNode* head)
    {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL)
            return NULL;

        //cout << "size is " << Size(head) << endl;
        if(k == Size(head))
        {
            head = reverseList(head);
            return head;
        } else if(k > Size(head)) {
            return head;
        } else if(k < Size(head)) {


    	ListNode * current = head;
    	ListNode * next = NULL;
    	ListNode * prev = NULL;
    	int count = 0;

	/*reverse first k nodes of the linked list */
	while(current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if (next != NULL)
	{
		head->next = reverseKGroup(next, k);
	}

	return prev;
        }

      //  return NULL;
    }
};
