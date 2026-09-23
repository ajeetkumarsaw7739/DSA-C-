Node* floydDetectLoop(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {

        slow = slow->next;

        // fast ke 2 steps safely check karo
        if(fast->next != NULL) {
            fast = fast->next->next;
        }
        else {
            return NULL;
        }

        // Loop detected
        if(slow == fast) {
            return slow;
        }
    }

    return NULL;
}