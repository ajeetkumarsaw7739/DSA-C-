void heapify(vector<int>& arr, int n, int i){

    // Assume current node is largest
    int largest = i;

    // Calculate left and right child index
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child exists and is greater than current largest
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    // Check if right child exists and is greater than current largest
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    // If largest is not the current node,
    // swap and heapify the affected subtree
    if(largest != i){

        swap(arr[largest], arr[i]);

        // Recursively heapify the subtree
        heapify(arr, n, largest);
    }
}


vector<int> mergeheaps(vector<int>& a, vector<int>& b, int n, int m){

    // Step 1: Merge both arrays into one array
    vector<int> ans;

    for(auto i : a){
        ans.push_back(i);
    }

    for(auto i : b){
        ans.push_back(i);
    }

    // Step 2: Build a Max Heap from merged array
    int size = ans.size();

    // Start from the last non-leaf node
    for(int i = size/2 - 1; i >= 0; i--){

        heapify(ans, size, i);
    }

    // Return the merged Max Heap
    return ans;
}