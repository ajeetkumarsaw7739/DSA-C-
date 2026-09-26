 void inorder(Node* root,vector<int>&inorderval){
        
        //base case
        if(root == NULL){
            return ;
        }
        
        //recursion call
        inorder(root->left,inorderval);
        
        inorderval.push_back(root->data);
        
        inorder(root->right,inorderval);
        
    }
    Node *flattenBST(Node *root) {
        
        vector<int> inorderval;
        
        inorder(root,inorderval);
        
        int n = inorderval.size();
        
        Node* newroot = new Node(inorderval[0]);
        Node* curr = newroot;
        
        for(int i=1;i<n;i++){
            
            Node* temp = new Node(inorderval[i]);
            
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        
        curr->left = NULL;
        curr->right = NULL;
        
        return newroot;
    }