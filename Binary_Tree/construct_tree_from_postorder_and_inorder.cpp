void createmapping(int in[], map<int,int>& nodetoindex, int n) {

    for(int i = 0; i < n; i++) {
        nodetoindex[in[i]] = i;
    }
}

Node* solve(int in[], int pos[], int &index,
            int inorderstart, int inorderend, int n,
            map<int,int>& nodetoindex) {

    // Base case
    if(index < 0 || inorderstart > inorderend) {
        return NULL;
    }

    // Create root node
    int element = pos[index--];

    Node* root = new Node(element);

    // Find element index in inorder
    int position = nodetoindex[element];

    // Recursive calls
    root->right = solve(in, pos, index,position + 1, inorderend, n, nodetoindex);

    root->left = solve(in, pos, index,inorderstart, position - 1, n, nodetoindex);

    return root;
}

Node* builttree(int in[], int pos[], int n) {

    int postorderindex = n - 1;

    map<int,int> nodetoindex;

    // Create node-to-index mapping
    createmapping(in, nodetoindex, n);

    Node* ans = solve(in, pos, postorderindex, 0, n - 1, n, nodetoindex);

    return ans;
}