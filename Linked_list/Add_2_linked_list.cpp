 Node* reverse(Node* &head) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void insertattail(Node* &head, Node* &tail, int d) {
        Node* temp = new Node(d);

        if (tail == NULL) {
            tail = temp;
            head = temp;
            return;
        }

        tail->next = temp;
        tail = temp;
    }

    Node* add(Node* &first, Node* &second) {
        int carry = 0;

        Node* anshead = NULL;
        Node* anstail = NULL;

        while (first != NULL || second != NULL || carry != 0) {

            int val1 = 0;
            if (first != NULL) {
                val1 = first->data;
            }

            int val2 = 0;
            if (second != NULL) {
                val2 = second->data;
            }

            int sum = val1 + val2 + carry;
            int digit = sum % 10;

            insertattail(anshead, anstail, digit);

            carry = sum / 10;

            if (first != NULL) {
                first = first->next;
            }

            if (second != NULL) {
                second = second->next;
            }
        }

        return anshead;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        
       // Step 1: Remove leading zeros
       while (head1 != NULL && head1->data == 0 && head1->next != NULL) {
           head1 = head1->next;
       }

       while (head2 != NULL && head2->data == 0 && head2->next != NULL) {
           head2 = head2->next;
       }
        // Step 1: Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);  

        // Step 2: Add both lists
        Node* ans = add(head1, head2);

        // Step 3: Reverse answer
        ans = reverse(ans);

        return ans;
    }