pair<bool,int> issumtreefast(Node* root){
        //base case
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        if(root->left == NULL && root->right == NULL){
            pair<bool,int>p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int>leftans = issumtreefast(root->left);
        pair<bool,int>rightans = issumtreefast(root->right);
        
        bool isleftsumtree = leftans.first;
        bool isrightsumtree = rightans.first;
        
        int leftsum = leftans.second;
        int rightsum = rightans.second;
        
        bool condn = root->data == leftsum + rightsum;
        
        pair<bool,int>ans;
        if(isleftsumtree && isrightsumtree && condn){
            ans.first = true;
            ans.second = root->data + leftsum + rightsum;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* node) {
        
        return issumtreefast(node).first;
    }