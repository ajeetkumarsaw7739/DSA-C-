pair<bool,int> isbalancedfast(Node* root){

    //base case
    if(root == NULL){
        return pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isbalancedfast(root->left);

    pair<bool,int> right = isbalancedfast(root->right);

    bool leftans = left.first;
    bool rightans = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    
    ans.second = max(left.second,right.second) + 1;

    if(leftans && rightans && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    
    return ans;
}

bool isbalanced(Node* root){
    return isbalancedfast(root).first;
}