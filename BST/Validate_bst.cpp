 bool isbst(Node* root,int min,int max){
        
        //base case
        if(root == NULL){
            return true;
        }
        
        if(root->data > min && root->data < max){
            
            bool left = isbst(root->left,min,root->data);
            
            bool right = isbst(root->right,root->data,max);
            
            return left && right;
        }
        else{
            return false;
        }
    }
    bool isBST(Node* root) {
        
        return isbst(root,INT_MIN,INT_MAX);
    }