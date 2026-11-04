 Node* divide(Node* head) {

        // Create dummy nodes for even and odd lists
        Node* even = new Node(-1);
        Node* head1 = even;
        Node* tail1 = even;

        Node* odd = new Node(-1);
        Node* head2 = odd;
        Node* tail2 = odd;

        // Traverse the original linked list
        Node* temp = head;

        while(temp != NULL){

            // Check if current node contains even data
            if(temp->data % 2 == 0){

                // Create a new node and add it to even list
                Node* curr = new Node(temp->data);
                tail1->next = curr;
                tail1 = curr;
            }
            else{

                // Create a new node and add it to odd list
                Node* curr = new Node(temp->data);
                tail2->next = curr;
                tail2 = curr;
            }

            // Move to the next node
            temp = temp->next;
        }

        // Connect even list with odd list
        tail1->next = head2->next;

        // Return the updated list (even elements first)
        return head1->next;
    }