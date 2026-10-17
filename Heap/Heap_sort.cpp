#include<iostream>
using namespace std;


void heapify(int arr[], int n, int i){

    int largest = i;

    int left = 2 * i;
    int right = 2 * i + 1;

    // Check left child
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    // Check right child
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    // If largest is not root
    if(largest != i){

        swap(arr[largest], arr[i]);

        // Heapify affected subtree
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[],int n){

    int size = n;

    while(size > 1){
        //step 1: swap
        swap(arr[size],arr[1]);
        size--;

        //step 2
        heapify(arr,size,1);
    }
}
int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Build Max Heap
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing the array now:" << endl;

    // 1-based indexing: print 1 to n-1
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    //heapsort
    heapsort(arr,n);

    cout << "Printing the sorted array " << endl;

    for(int i=1;i<=n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}