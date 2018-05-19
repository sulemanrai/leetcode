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
    /* sorts the linked list by changing next pointers (not data) */
    void MergeSort(struct ListNode** headRef)
    {
         /*1) If head is NULL or there is only one element in the Linked List
            then return*/
        if(*headRef == NULL || (*headRef)->next == NULL)
            return;


        /*2) Else divide the linked list into two halves.
        FrontBackSplit(head, &a, &b); /* a and b are two halves */
       ListNode* a = new ListNode(0);
       ListNode* b = new ListNode(0);

       FrontBackSplit(*headRef,&a,&b);

        /*3) Sort the two halves a and b. */
       MergeSort(&a);
       MergeSort(&b);

       *headRef = SortedMerge(a, b);
    }

    /* function prototypes */
    struct ListNode* SortedMerge(struct ListNode* a, struct ListNode* b)
    {
//         	// Your Code Here
       if(a == NULL)
           return b;

        if(b == NULL)
            return a;

        if(a == NULL && b == NULL)
           return NULL;

	struct ListNode * list1 = a;
	struct ListNode * list2 = b;

	struct ListNode * sorting = NULL;
	struct ListNode * new_head = NULL;

	if(list1->val <= list2->val)
	{
		sorting = list1;
		list1 = sorting->next;
	} else
	{
		sorting = list2;
		list2 = sorting->next;
	}
	new_head = sorting;
	while(list1 && list2)
	{
		if(list1->val <= list2->val)
		{
			sorting->next = list1;
			sorting = list1;
			list1 = sorting->next;
		} else if(list2->val <= list1->val)
		{
			sorting->next = list2;
			sorting = list2;
			list2 = sorting->next;
		}
	}

	if(list1 == NULL)
	{
		sorting->next = list2;
	}

	if(list2 == NULL)
	{
		sorting->next = list1;
	}
	return new_head;

	}



    void FrontBackSplit(struct ListNode* source,
        struct ListNode** frontRef, struct ListNode** backRef)
    {
        ListNode * prev = NULL;
        ListNode * slowptr = source;
        ListNode * fastptr = source;
        ListNode * a = *frontRef;
        ListNode * b = *backRef;

        while(fastptr != NULL && fastptr->next != NULL)
        {
            prev = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        prev->next = NULL;
        *frontRef = source;
        *backRef = slowptr;
    }

    ListNode* sortList(ListNode* head) {
        MergeSort(&head);
        return head;
    }
};
