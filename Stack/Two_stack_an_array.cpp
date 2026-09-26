class twoStacks {
    int arr[100];

    // Total size of array
    int size = 100;
    int top1;
    int top2;

  public:

    // Constructor
    twoStacks() {
        top1 = -1;      
        top2 = size;     
    }

    // Push element into Stack 1
    void push1(int x) {

        // Space available hai agar top1 aur top2 ke beech
        // kam se kam 1 empty position ho
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = x;
        }
    }

    // Push element into Stack 2
    void push2(int x) {

        // Check if space is available
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = x;
        }
    }

    // Pop element from Stack 1
    int pop1() {
        
        if(top1 >= 0) {
            int ans = arr[top1];

            top1--;

            return ans;
        }
        else {
            return -1;
        }
    }

    // Pop element from Stack 2
    int pop2() {

        if(top2 < size) {
            int ans = arr[top2];

            top2++;

            return ans;
        }
        else {
          
            return -1;
        }
    }
};