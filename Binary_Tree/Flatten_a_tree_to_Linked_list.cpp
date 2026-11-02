void flatten(Node* root) {
    
    // Initialize current pointer at root
    Node* curr = root;
    
    while(curr != NULL){
        
        if(curr->left){
            
            // Find the rightmost node of the left subtree
            Node* pred = curr->left;
            
            while(pred->right){
                // Move to the rightmost node
                pred = pred->right;
            }
            
            // Connect the rightmost node to the original right subtree
            pred->right = curr->right;
            
            // Move the left subtree to the right
            curr->right = curr->left;
            
            // Set the left pointer to NULL
            curr->left = NULL;
        }
        
        // Move to the next node using the right pointer
        curr = curr->right;
    }
}