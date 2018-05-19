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
    void prettyPrintLinkedList(ListNode* node) {
  while (node && node->next) {
      cout << node->val << "->";
      node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}
    ListNode* insertionSortList(ListNode* head) {

        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        ListNode * j = NULL;
        ListNode * key = NULL;
        ListNode * i = head;

        for(j = head->next; j != NULL; j = j->next )
        {
            key = j;
            for(i = head; i != key; i = i->next)
            {
                if(i->val > key->val)
                {
                    int temp = i->val;
                    i->val = key->val;
                    key->val = temp;
                }
            }
            cout << endl;
        }

        return head;
    }
};
