class compare {
  public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {

        int k = arr.size();

        priority_queue<Node*, vector<Node*>, compare> minheap;

        if (k == 0) {
            return NULL;
        }

        // Step 1: Har list ka first node insert karo
        for (int i = 0; i < k; i++) {
            if (arr[i] != NULL) {
                minheap.push(arr[i]);
            }
        }

        Node* head = NULL;
        Node* tail = NULL;

        while (!minheap.empty()) {

            Node* top = minheap.top();
            minheap.pop();

            // Next node ko heap mein insert karo
            if (top->next != NULL) {
                minheap.push(top->next);
            }

            if (head == NULL) {
                head = top;
                tail = top;
            }
            else {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};
