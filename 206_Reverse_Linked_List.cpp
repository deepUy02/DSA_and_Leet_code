Approach-1

  ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL, *next = NULL;

        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current = next;
        }
        head=prev;
        return head;
}

Approach-2 //recursion
  
ListNode* reverse1(ListNode* &head)
    {
        //base case
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* forward = reverse1(head->next);
        head -> next -> next = head;
        head -> next = NULL;
        return forward;
    }
    ListNode* reverseList(ListNode* head) {
        return reverse1(head);
    }
