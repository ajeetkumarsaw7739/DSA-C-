void inorder(Node* root,int &cnt){

    //base case
    if(root == NULL){
        return ;
    }

    inorder(root->left,cnt);

    if(root->left == NULL && root->right == NULl){
        cnt++;
    }

    inorder(root->right);
}

int noofleafNodes(Node* root){

    int cnt = 0;

    inorder(root);

    return cnt;
}