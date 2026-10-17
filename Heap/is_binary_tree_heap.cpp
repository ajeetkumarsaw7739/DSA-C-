int countnodes(Node* root){

    // Base case:
    // If tree is empty, there are 0 nodes
    if(root == NULL){
        return 0;
    }

    // Count current node + left subtree nodes + right subtree nodes
    int ans = 1 + countnodes(root->left) + countnodes(root->right);

    return ans;
}


bool iscbt(Node* tree, int index, int cnt){

    // If node is NULL, this position is valid
    if(tree == NULL){
        return true;
    }

    // In a Complete Binary Tree,
    // every node must have an index less than total node count
    if(index >= cnt){
        return false;
    }

    else{

        // For 0-based indexing:
        // Left child  = 2*index + 1
        // Right child = 2*index + 2
        bool left = iscbt(tree->left, 2*index+1, cnt);

        bool right = iscbt(tree->right, 2*index+2, cnt);

        // Tree is CBT only if both left and right subtrees are CBT
        return (left && right);
    }
}


bool ismaxorder(Node* tree){

    // Leaf node:
    // A leaf has no children, so max-heap property is satisfied
    if(tree->left == NULL && tree->right == NULL){
        return true;
    }

    // If only left child exists,
    // parent must be greater than left child
    if(tree->right == NULL){
        return (tree->data > tree->left->data);
    }

    else{

        // Check max-heap property in left subtree
        bool left = ismaxorder(tree->left);

        // Check max-heap property in right subtree
        bool right = ismaxorder(tree->right);

        // Current node must be greater than both children
        // AND both subtrees must satisfy max-heap property
        return (left && right &&
                (tree->data > tree->left->data &&
                 tree->data > tree->right->data));
    }
}


bool isHeap(Node* tree) {

    // Start indexing from 0
    int index = 0;

    // Count total number of nodes
    int totalcount = countnodes(tree);

    // A Binary Tree is a Max Heap if:
    // 1. It is a Complete Binary Tree
    // 2. It follows Max Heap order property
    if(iscbt(tree, index, totalcount) && ismaxorder(tree)){
        return true;
    }
    else{
        return false;
    }
}