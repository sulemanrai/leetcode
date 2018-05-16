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
        void Print(ListNode *head)
    {
        ListNode * tmp = head;
        while(tmp != NULL)
        {
            cout << tmp->val << " " ;
            tmp = tmp->next;
        }
            cout << "\n" << endl;
    }
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;

        ListNode * prior = NULL;
        ListNode * prev = head;
        ListNode * curr = prev->next;
        ListNode * tmp = NULL;
        ListNode * tmp1 = NULL;
        ListNode * tmp2 = NULL;

        bool flag = false;

        while(1)
        {

            if(prev->val == curr->val)
            {

                  if(curr->next == NULL && prior == NULL)
                {

                           delete prev, curr;
                           return NULL;
                 } else if(curr->next == NULL && prior != NULL)
                  {
                      delete prev, curr;
                      prior->next = NULL;

                  }

                if(prior != NULL)
                {

                    if(prev->val == curr->val)
                   {

                        if(curr->next == NULL)
                        {
                             return prior;
                        }

                        while(prev->val == curr->val)
                        {
                            prev = prev->next;
                            curr = curr->next;
                            if(curr == NULL) {
                                prior->next = prev->next;
                                delete prev;
                                break;
                            }
                        }


                        if(curr != NULL) {
                         prior->next = curr;
                            prev = curr;
                            curr = curr->next;

                        }

                   }
                } else if(prior == NULL)
                {
                      while(prev->val == curr->val)
                        {
                            prior = prev;
                            prev = prev->next;
                            curr = curr->next;
                            if(curr == NULL) {
                                prior->next = prev->next;
                                delete prev;
                                break;
                            }
                        }
                    head = curr;
                    prev = head;
                    if(curr != NULL) {
                    curr = curr->next;
                    } else {
                        curr = NULL;
                    }
                    prior = NULL;

                }

            } else if(prev->val != curr->val)
            {

           if(prev != NULL) {
                prior = prev;
                } else {
                    prior = NULL;
                }
               prev = prev->next;
                curr = curr ->next;
            }
            if(curr == NULL)
                break;

        }
        return head;
    }
};
