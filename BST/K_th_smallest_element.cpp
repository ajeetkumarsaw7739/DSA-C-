 int solve(Node* root,int &i,int k){
        
        //base case
        if(root == NULL){
            return -1;
        }
        
        //left
        int left = solve(root->left,i,k);
        
        if(left != -1){
            return left;
        }
        
        i++;
        //node
        if(i == k){
            return root->data;
        }
        
        //right
        return solve(root->right,i,k);
        
    }
    int kthSmallest(Node *root, int k) {
        
        int i = 0;
        int ans = solve(root,i,k);
        
        return ans;
    }