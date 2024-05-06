Approach-1(Using Stack)
TC:-O(N)
SC:-O(N)

ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* curr = head;
        while(curr != NULL){
            st.push(curr);
            curr = curr-> next;
        }
        curr = st.top();
        st.pop();
        int maxNode = curr->val;
        ListNode* resultList = new ListNode(curr->val);
        while(!st.empty()){
            curr = st.top();
            st.pop();
            if(curr->val < maxNode){
                continue;
            }
            else{
                ListNode* newNode = new ListNode(curr->val);
                newNode->next = resultList;
                resultList = newNode;
                maxNode = curr->val;
            }
        }
        return resultList;
    }

Approach-2(Using Recursion)

ListNode* removeNodes(ListNode* head) {
        //Base Case
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* nextNode = removeNodes(head->next);
        if(head->val < nextNode->val){
            delete head;
            return nextNode;
        }
        head->next = nextNode;
        return head;
    }

Approach-3(Reverse it)
TC:-O(N)
SC:-O(1)

ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* lastNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return lastNode;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        
        int maxNode = -1;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            maxNode = max(maxNode, curr->val);
            if(curr->val < maxNode){
                prev->next = curr ->next;
                ListNode* temp = curr;
                curr = curr->next;
                delete (temp);
            }
            else{
                prev= curr;
                curr= curr->next;
            }
        }
        return reverseList(head);
    }