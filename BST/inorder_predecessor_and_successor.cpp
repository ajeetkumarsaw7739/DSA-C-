vector<Node*> findPreSuc(Node* root, int key) {

        // find key
        Node* temp = root;
        Node* pred = NULL;
        Node* succ = NULL;

        while(temp != NULL && temp->data != key){

            if(temp->data > key){
                succ = temp;              // change
                temp = temp->left;
            }
            else{
                pred = temp;              // change
                temp = temp->right;
            }
        }

        // pred and succ

        // pred
        if(temp != NULL) {
            Node* lefttree = temp->left;

            while(lefttree != NULL){
                pred = lefttree;          // change
                lefttree = lefttree->right;
            }

            // succ
            Node* righttree = temp->right;

            while(righttree != NULL){
                succ = righttree;         // change
                righttree = righttree->left;
            }
        }

        return {pred, succ};
    }