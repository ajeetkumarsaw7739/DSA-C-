 vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;

        if(root == NULL){
            return ans;
        }

        queue<Node*> q;
        q.push(root);

        bool lefttoright = true;

        while(!q.empty()){

            int size = q.size();
            vector<int> level(size);

            // Process current level
            for(int i = 0; i < size; i++){

                Node* frontnode = q.front();
                q.pop();

                int index;

                if(lefttoright){
                    index = i;
                }
                else{
                    index = size - i - 1;
                }

                level[index] = frontnode->data;

                if(frontnode->left){
                    q.push(frontnode->left);
                }

                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }

            // Add current level to answer
            for(auto ele : level){
                ans.push_back(ele);
            }

            // Change direction
            lefttoright = !lefttoright;
        }

        return ans;
    }