void solve(Node* root,vector<int>&ans,int lvl){
        //base case
        if(root == NULL){
            return ;
        }
        
        if(lvl == ans.size()){
            ans.push_back(root->data);
        }
        
        //recursive call
        solve(root->left,ans,lvl+1);
        
        solve(root->right,ans,lvl+1);
    }
    vector<int> leftView(Node *root) {
        vector<int>ans;
        int lvl = 0;
    
        solve(root,ans,lvl);
        return ans;
    }
