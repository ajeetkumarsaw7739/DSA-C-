#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    // Constructor
    // Heap ka size initially 0 hai
    // Indexing 1 se start kar rahe hain
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){

        // Step 1: Heap ka size increase karo
        size = size + 1;

        // Step 2: New element ko last position par insert karo
        int index = size;
        arr[index] = val;

        // Step 3: Element ko parent ke saath compare karo
        // aur correct position par le jao 
        while(index > 1){

            // Parent ka index = child index / 2
            int parent = index / 2;

            // Min Heap condition:
            // Parent hamesha child se chhota ya equal hona chahiye
            if(arr[parent] > arr[index]){

                // Agar parent bada hai to swap karo
                swap(arr[parent], arr[index]);

                // Ab current element parent ki position par aa gaya
                index = parent;
            }
            else{

                // Agar parent already chhota hai,
                // to Min Heap property maintain hai
                return;
            }
        }
    }

    // Delete root from Min Heap
    void deletefromheap(){

        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }

        // Step 1: Last element ko root par lao
        arr[1] = arr[size];

        // Step 2: Last element remove karo
        size--;

        // Step 3: Heapify Down
        int i = 1;

        while(i <= size){

            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            // Dono children present hain
            if(rightindex <= size){

                // Min Heap mein smaller child choose karo
                if(arr[leftindex] < arr[rightindex]){

                    // Left child chhota hai
                    if(arr[i] > arr[leftindex]){
                        swap(arr[i], arr[leftindex]);
                        i = leftindex;
                    }
                    else{
                        return;
                    }
                }
                else{

                    // Right child chhota hai
                    if(arr[i] > arr[rightindex]){
                        swap(arr[i], arr[rightindex]);
                        i = rightindex;
                    }
                    else{
                        return;
                    }
                }
            }

            // Sirf left child present hai
            else if(leftindex <= size){

                if(arr[i] > arr[leftindex]){
                    swap(arr[i], arr[leftindex]);
                    i = leftindex;
                }
                else{
                    return;
                }
            }

            // Koi child nahi hai
            else{
                return;
            }
        }
    }

    void print(){

        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main(){

    heap h;

    h.insert(50);
    h.insert(12);
    h.insert(44);
    h.insert(22);
    h.insert(30);

    // Min Heap print
    h.print();
    h.deletefromheap();
    h.print();

    return 0;
}