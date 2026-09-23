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
    Node* merge(Node* &left,Node* &right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(left != NULL && right != NULL){
            if(left->data < right->data){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        // base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        //break linked list intto 2 halfs after finding mid
        Node* mid = getmid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        //recursive call to sort both halfs
        left = mergeSort(left);
        right = mergeSort(right);
        
        //merge both left and right halfs
        Node* result = merge(left,right);
        
        return result;
    }