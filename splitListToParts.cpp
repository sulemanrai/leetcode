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
        int count = 0;
        ListNode * tmp = head;
        while(tmp != NULL)
        {
            count++;
            tmp = tmp -> next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> vec;

        /* If size is less then k*/
        if(Size(root) < k)
        {
            int number_of_null_nodes = (k - Size(root));

            ListNode * prev = NULL;
            ListNode * curr = root;
            ListNode * tmp = NULL;
            while(curr != NULL)
            {
                prev = curr;
                curr = curr->next;
                tmp = new ListNode(prev->val);
                vec.push_back(tmp);
            }

            int i = 0;
            while(i != number_of_null_nodes)
            {
                vec.push_back(NULL);
                i++;
            }
        } else if(Size(root) == k)
        {
            ListNode * prev = NULL;
            ListNode * curr = root;
            ListNode * tmp = NULL;
            while(curr != NULL)
            {
                prev = curr;
                curr = curr->next;
                tmp = new ListNode(prev->val);

                vec.push_back(tmp);

            }
        } else if (Size(root) > k)
        {

            if(Size(root) % k == 0)
            {
                if(k == 1)
                {
                    vec.push_back(root);
                } else if(k != 1)
                {
                    ListNode * Next = root->next;
                    ListNode * curr = root;
                    ListNode * tmp = root;
                     ListNode * prev = NULL;

                    int size_of_list = Size(root) / k ;
                    int i = 1;
                   while(curr != NULL)
                   {
                       prev = curr;
                       curr = curr->next;
                        if(i == size_of_list)
                       {
                         vec.push_back(tmp);
                            tmp = curr;
                            prev->next = NULL;
                            i = 0;
                        }
                       i++;
                   }
                }
            } else if(Size(root) % k != 0)
            {
                 int size_of_list = ceil((double)Size(root) / (double)k) ;
                 int modular_number = Size(root) % k ;

                 ListNode * curr = root;
                 ListNode * tmp = root;
                 ListNode * prev = NULL;

                int i = 0;
                int elements = 0;
                int List_size = 0;
                while(curr != NULL)
                {
                    elements = Size(curr) / k ;
                     int modular_number = Size(curr) % k ;
                    if(modular_number == 0)
                    {
                        List_size = elements;
                    } else if(modular_number != 0) {
                        List_size = elements + 1;
                    }
                    while(i != List_size)
                     {
                         prev = curr;
                         curr = curr -> next;
                         i++;
                     }
                    vec.push_back(tmp);
                    curr = prev->next;
                    prev->next = NULL;
                    tmp = curr;
                    i = 0;
                     k--;
                     if(k == 0)
                     {
                         k = 1;
                     }

                }
            }
        }

        return vec;
    }
};
