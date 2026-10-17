#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    // Constructor
    // Initially heap ka size 0 hai
    // arr[0] ko -1 rakha hai because heap indexing 1 se start kar rahe hain
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

        // Step 3: Element ko parent ke saath compare karke
        // correct position par le jao (Heapify Up)
        while(index > 1){

            // Parent ka index = child index / 2
            int parent = index / 2;

            // Max Heap condition:
            // Parent hamesha child se bada ya equal hona chahiye
            if(arr[parent] < arr[index]){

                // Agar child bada hai to parent aur child ko swap karo
                swap(arr[parent],arr[index]);

                // Ab current index parent ban gaya
                // Isliye next parent ke saath compare karenge
                index = parent;
            }
            else{
                // Agar parent already bada hai,
                // to heap property maintain ho rahi hai
                return;
            }
        }
    }

    void print(){

        // Heap ko level-order/array representation mein print kar rahe hain
        // Heap internally complete binary tree hota hai
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Delete root from Max Heap
    void deletefromheap(){

        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }

        // Step 1: Last element ko root par lao
        arr[1] = arr[size];

        // Step 2: Last element remove
        size--;

        // Step 3: Heapify Down
        int i = 1;

        while(i <= size){

            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            // Dono children present hain
            if(rightindex <= size){

                // Max Heap mein larger child choose karo
                if(arr[leftindex] > arr[rightindex]){

                    if(arr[i] < arr[leftindex]){
                        swap(arr[i], arr[leftindex]);
                        i = leftindex;
                    }
                    else{
                        return;
                    }
                }
                else{

                    if(arr[i] < arr[rightindex]){
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

                if(arr[i] < arr[leftindex]){
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

};

int main(){

    heap h;

    // Elements insert kar rahe hain
    h.insert(50);
    h.insert(12);
    h.insert(44);
    h.insert(22);
    h.insert(30);

    // Max Heap print
    h.print();

    h.deletefromheap();
    h.print();
    
    return 0;
}