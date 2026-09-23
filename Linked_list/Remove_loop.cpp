    Node* floydDetectloop(Node* &head){
        if(head == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                return slow;
            }
        }
        return NULL;
    }
    Node* getstartingNode(Node* &head){
        if(head == NULL){
            return NULL;
        }
        Node* intersection = floydDetectloop(head);
        
        if(intersection == NULL){
            return NULL;
        }
        Node* slow = head;
        
        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
    void removeLoop(Node* head) {
        //empty list
        if(head == NULL){
            return ;
        }
        Node* startofloop = getstartingNode(head);
        
        if(startofloop == NULL){
            return ;
        }
        
        Node* temp = startofloop;
        
        while(temp->next != startofloop){
            temp = temp->next;
        }
        temp->next = NULL;
    }