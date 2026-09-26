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
    
    Node* inorderbst(int s,int e,vector<int>&in){
        
        //base case
        if(s > e){
            return NULL;
        }
        
        int mid = s + (e - s) / 2;
        
        Node* root = new Node(mid);
        
        root->left = inorderbst(s,mid-1,in);
        
        root->right = inorderbst(mid+1,e,in);
        
        return root;
    }
    Node* balanceBST(Node* root) {
        
        vector<int>inorderval;
        //store inorder -> sorted value
        inorder(root,inorderval);
        
        return inorderbst(0,inorderval.size()-1,inorderval);
        
    } 