class kStacks {

    // main array to store elements
    int *arr;

    // top[i] = top index of ith stack
    int *top;

    // next[i] = next index
    int *next;

    int n;          
    int k;          
    int freeSpot;   

  public:

    kStacks(int n, int k) {

        this->n = n;
        this->k = k;

        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // Initially all stacks are empty
        for(int i = 0; i < k; i++) {
            top[i] = -1;
        }

        // Create free list
        for(int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }

        next[n - 1] = -1;

        // First free position
        freeSpot = 0;
    }

    void push(int x, int i) {

        // Overflow
        if(freeSpot == -1) {
            return;
        }

        // Get free index
        int index = freeSpot;

        // Update freeSpot
        freeSpot = next[index];

        // Store element
        arr[index] = x;

        // Connect new element with old top
        next[index] = top[i - 1];

        // Update top
        top[i - 1] = index;
    }

    int pop(int i) {

        // Underflow
        if(top[i - 1] == -1) {
            return -1;
        }

        // Get top index
        int index = top[i - 1];

        // Update top
        top[i - 1] = next[index];

        // Put this index back into free list
        next[index] = freeSpot;

        freeSpot = index;

        // Return element
        return arr[index];
    }
};