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
	    int size = 0;
	    while(head != NULL)
	    {
		    size++;
		    head = head->next;
	    }
	    return size;
    }
    void PrintList(ListNode* head)
    {
        while(head != NULL)
        {
            cout << head -> val << " ";
            head = head -> next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* temp1 = l1;
        struct ListNode* temp2 = l2;

        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;

        //cout << " Size " << Size(l1) << endl;
        if(Size (l1) > Size (l2))
        {
            int diff = Size(l1) - Size(l2);
            cout << " diff " << diff << endl;
            if(Size(l2) > 1) {
            int i = 0;
            while(i != Size (l2)) {
               // temp2->next = new ListNode(0);
                if(temp2->next != NULL) {
                    temp2 = temp2->next;
                }
                i++;
            }
        }
            cout << "temp2" << temp2->val;
            int k = 0;
            while(k != diff) {
                temp2->next = new ListNode(0);
                temp2 = temp2->next;
                k++;
            }
        } else if(Size (l2) > Size (l1))
        {
            int diff = Size(l2) - Size(l1);
            //cout << " diff " << diff << endl;
            if(Size(l1) > 1) {
            int i = 0;
            while(i != Size (l1)) {
                //temp1->next = new ListNode(0);
                if(temp1->next != NULL) {
                    temp1 = temp1->next;
                }
                i++;
            }
            }
             int j = 0;
                 while(j != diff) {
                temp1->next = new ListNode(0);
                temp1 = temp1->next;
                j++;
            }
        }

        temp1 = l1;
        temp2 = l2;

        PrintList(l1);
        cout << endl ;
        PrintList(l2);

        int carry = 0;
        int sum = 0;
        while(temp1 && temp2)
        {
            if(carry == 0)
            {
                sum = temp1->val + temp2->val;
            } else {
                sum = temp1->val + temp2->val + carry;
            }
            if(sum % 10 != 0)
            {
                //carry = sum / 10;
                 carry = sum / 10;
                // cout<<" sum1 " << sum << "carry1 " << carry <<endl;
                sum = sum % 10;
                //sum = sum % 10 + carry;
                 current->next = new ListNode(sum);
                 current = current->next;
            } else if(sum % 10 == 0) {
                 carry = sum / 10;
                 sum = sum % 10;
                //cout << " sum2 " << sum << " carry2 " << carry <<endl;
                current->next = new ListNode(sum);
                current = current->next;
            }


            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(carry != 0)
            current->next = new ListNode(carry);

        return dummyHead->next;
    }
};
