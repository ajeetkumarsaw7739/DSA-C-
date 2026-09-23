Node* removeDuplicates(Node* head) {
        // empty list
        if(head == NULL){
            return NULL;
        }
        unordered_set<int>seen;
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL){
            if(seen.find(curr->data) != seen.end()){
                prev->next = curr->next;
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            else{
                seen.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }