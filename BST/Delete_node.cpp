class Solution {
public:
    int minval(TreeNode* root){

        TreeNode* temp = root;

        while(temp->left != NULL){
            temp = temp->left;
        }

        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        //base case
        if(root == NULL){
            return root;
        }

        if(root->val == key){

            //0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            //1 child
            //left child
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;

                delete root;
                return temp;
            }

            //right child
            if(root->left == NULL && root->right != NULL){

                TreeNode* temp = root->right; 

                delete root;
                return temp;
            }

            //2 child
            if(root->left != NULL && root->right != NULL){
                int mini = minval(root->right);

                root->val = mini;
                root->right = deleteNode(root->right,mini);

                return root;
            }
        }
        else if (root->val > key){
            //left part mein jao
            root->left = deleteNode(root->left,key);
            return root;
        }
        else{
            //right part mein jao
            root->right = deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};