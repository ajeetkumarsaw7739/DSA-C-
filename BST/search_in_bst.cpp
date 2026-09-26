class Solution {
  public:
    bool search(Node* root, int key) {
        
        Node* temp = root;
        
        while(temp != NULL){
            
            if(key == temp->data){
                return true;
            }
            
            if(key > temp->data){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        return false;
    }
};