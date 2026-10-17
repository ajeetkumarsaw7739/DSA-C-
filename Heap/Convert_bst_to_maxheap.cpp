 void inorder(Node* root,vector<int>&ans){
        
        //base case
        if(root == NULL){
            return ;
        }
        
        //recursion call
        inorder(root->left,ans);
        
        ans.push_back(root->data);
        
        inorder(root->right,ans);
    }
    
    void postorder(Node* root,vector<int>&ans,int &index){
        
        //base case
        if(root == NULL){
            return ;
        }
        
        postorder(root->left,ans,index);
        
        postorder(root->right,ans,index);
        
        root->data = ans[index++];
    }
    void convertToMaxHeap(Node* root) {
        
        vector<int>ans;
        
        // Step 1: BST ka inorder = sorted array
        inorder(root,ans);
        
        // Step 2: sorted values ko postorder mein assign
        int index = 0;
        postorder(root,ans,index);
    }