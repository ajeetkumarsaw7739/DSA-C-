vector<vector<int>> verticalOrder(Node *root) {

        map<int, map<int, vector<int>>> nodes;

        queue<pair<Node*, pair<int,int>>> q;

        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        // root ko queue mein push
        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty()){

            pair<Node*, pair<int,int>> temp = q.front();
            q.pop();

            Node* frontnode = temp.first;

            int hd = temp.second.first;
            int lvl = temp.second.second;

            // data store
            nodes[hd][lvl].push_back(frontnode->data);

            // left
            if(frontnode->left){
                q.push(make_pair(
                    frontnode->left,
                    make_pair(hd - 1, lvl + 1)
                ));
            }

            // right
            if(frontnode->right){
                q.push(make_pair(
                    frontnode->right,
                    make_pair(hd + 1, lvl + 1)
                ));
            }
        }

        // map ko traverse karke answer banana
        for(auto i : nodes){

            vector<int> temp;

            for(auto j : i.second){

                for(auto k : j.second){
                    temp.push_back(k);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }