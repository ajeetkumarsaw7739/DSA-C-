Node* floydetect(Node* &head){
        if(head == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }
    int cycleStart(Node* head) {
        if(head == NULL){
            return -1;
        }
        
        Node* intersection = floydetect(head);
        
        if(intersection == NULL){
            return -1;
        }
        
        Node* slow = head;
        
        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow->data;
    }