 Node* getmid(Node* &head){
        if(head == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* reverse(Node* &head){
        if(head == NULL){
            return NULL;
        }
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        if(head->next == NULL){
            return true;
        }
        //step 1 find middle
        Node* middle = getmid(head);
        if(middle == NULL){
            return false;
        }
        //step 2 reverse linked list after middle
        Node* temp = middle->next;
        middle->next = reverse(temp);

        //step3 compare both value
        Node* head1 = head;
        Node*head2 = middle->next;

        while(head2 != NULL){
            if(head2->data != head1->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        //step4 repeat step2
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
        
    }