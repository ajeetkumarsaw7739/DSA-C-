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
    bool findTarget(Node *root, int target) {
        
        vector<int> ans;
        
        inorder(root,ans);
        
        int i = 0;
        int j = ans.size()-1;
        
        while(i < j){
            
            int sum = ans[i] + ans[j];
            
            if(sum == target){
                return true;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }