class solution {
    public:
    
    Node* minval(Node* root){

        Node* temp = root;

        while(temp->left != NULL){
            temp = temp->left;
        }

        return temp->data;
    }

    Node* maxval(Node* root){

        Node* temp = root;

        while(temp->right != NULL){
            temp = temp->right;
        }

        return temp->data;
    }
    
};