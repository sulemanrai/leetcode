    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL)
            return NULL;

        if(head->next->next == head)
            return head;

        ListNode * slowptr = head;
        ListNode * fastptr = head;
        ListNode * loopnode = NULL;

        while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if(slowptr == fastptr)
            {
                loopnode = slowptr;
                break;
            }
        }
        if(loopnode != NULL)
        {
            ListNode * start = loopnode;
            int number_of_nodes_in_loop = 1;
            while(start->next != loopnode)
            {
                number_of_nodes_in_loop++;
                start = start->next;
            }

            start = head;
            ListNode *tmp = head;
            int count = 0;
            while(count != number_of_nodes_in_loop)
            {
                tmp = tmp->next;
                count++;
            }

            while(1)
            {
                tmp = tmp->next;
                start = start->next;
                if(tmp == start)
                {
                   loopnode = tmp;
                    break;
                }
            }
        } else {
            loopnode = NULL;
        }

        return loopnode;

    }
