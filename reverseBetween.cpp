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
     void print(ListNode * head)
    {
        ListNode * tmp = head;

        while(tmp != NULL)
        {
            cout << ' ' << tmp->val;
            tmp = tmp->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n < m || n == m)
            return head;

        ListNode * prevM = NULL;
        ListNode * nextN = NULL;
        ListNode * M = head;
        ListNode * N = head;

        int i = 1, j = 1;
        while(i != m) {
            prevM = M;
            M = M->next;
            i++;
        }

        while(j != n) {
            N = N->next;
            j++;
        }
        if(N != NULL)
        {
            nextN = N->next;
        }

        ListNode * previous = NULL;
        ListNode * current = M;
        ListNode * Next = NULL;

        while(current != nextN)
        {
            Next = current->next;
            current->next = previous;
            previous = current;
            current = Next;
        }
        if(prevM != NULL) {
          prevM->next = previous;
            ListNode * tmp = prevM;
            while(tmp->next){
            tmp = tmp->next;
            }
            tmp->next = nextN;
        } else {
            if(nextN!= NULL)
            {
               ListNode * tmp = previous;
            while(tmp->next){
            tmp = tmp->next;
            }
            tmp->next = nextN;
            }
            return previous;
        }

        return head;
    }
};
