 Node* findLCA(Node* root, Node* n1, Node* n2) {
        
        while(root != NULL){
            
            if(root->data < n1->data && root->data < n2->data){
                
                root = root->right;
            }
            else if(root->data > n1->data && root->data > n2->data){
                
                root = root->left;
            }
            else{
                return root;
            }
        }
        return NULL;
    }