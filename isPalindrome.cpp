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
    void reverseList(ListNode** head) {

        ListNode * prev = NULL;
        ListNode * curr = *head;
        ListNode * Next = NULL;

        while(curr != NULL)
        {
            Next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = Next;

        }
        *head = prev;
}
    /* Function to check if two input lists have same data*/
bool compareLists(struct ListNode* head1, struct ListNode *head2)
{
    bool isSame = false;
    ListNode * temp1 = head1;
    ListNode * temp2 = head2;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->val != temp2->val)
        {
            isSame = false;
            break;
        } else {
            isSame = true;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return isSame;
}
    void Print(ListNode* head)
    {
        ListNode* ptr1 = head;

        while(ptr1 != NULL)
        {
            cout << ptr1->val << " ";
            ptr1 = ptr1 ->next;
        }
        cout << endl;
    }
    bool isPalindrome(ListNode* head) {

        if(head == NULL)
            return true;

    ListNode * slow_ptr = head, *fast_ptr = head;
    ListNode * second_half = NULL;
    ListNode * prev_of_slow_ptr = NULL;
    ListNode * midnode = NULL;  // To handle odd size list

        int i = 0;
    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        prev_of_slow_ptr = slow_ptr;
        if(i == 0)
        {
            slow_ptr = slow_ptr ->next;
            fast_ptr = fast_ptr ->next;
            i =1;
        } else if(i == 1)
        {
            fast_ptr = fast_ptr ->next;
            i = 0;
        }
    }
        // if (fast_ptr != NULL)
        // {
        //     midnode = slow_ptr;
        //     slow_ptr = slow_ptr->next;
        // }
      // cout << " midnode " << midnode->val << " slow_ptr " << slow_ptr->val << " prev_of_slow_ptr " << prev_of_slow_ptr->val<<endl;
        second_half = slow_ptr;
        reverseList(&second_half);

        return compareLists(head,second_half);
    }
};
