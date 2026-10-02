class kQueues {

  public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int freespot;
    int *next;
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        
        for(int i=0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i=0;i<n;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freespot = 0;
    }

    void enqueue(int x, int i) {
        //over flow
        if(freespot == -1){
            return ;
        }
        //find first free index
        int index = freespot;
        
        //update freespot
        freespot = next[index];
        
        //check whether first element
        if(front[i] == -1){
            front[i] = index;
        }
        else{
            //link new element to the prev element
            next[rear[i]] = index;
        }
        //update next
        next[index] = -1;
        
        //update rear
        rear[i] = index;
        
        //push element
        arr[index] = x;
    }

    int dequeue(int i) {
        //under flow
        if(front[i] == -1){
            return -1;
        }
        //find index to pop
        int index = front[i];
        
        //front ko aage badhao
        front[i] = next[index];
        
        //freespot ko manage karo
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
        return freespot == -1;
    }
};
