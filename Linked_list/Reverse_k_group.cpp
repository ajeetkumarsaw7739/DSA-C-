    Node *reverseKGroup(Node *head, int k) {
        //base case
        if(head == NULL){
            return NULL;
        }
        //step1: reverse first k nodes
        Node* next = NULL;
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 0;
        
        while(curr != NULL && cnt < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        //step2:recursion call
        if(next != NULL){
            head->next = reverseKGroup(next,k);
        }
        //step 3: return head of reversed list
        return prev;
        
    }