vector<int> topView(Node *root) {

        vector<int> ans;

        if(root == NULL) {
            return ans;
        }

        map<int, int> topnode;

        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while(!q.empty()) {

            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontnode = temp.first;
            int hd = temp.second;

            // Store the first node at each horizontal distance
            if(topnode.find(hd) == topnode.end()) {
                topnode[hd] = frontnode->data;
            }

            // Left child
            if(frontnode->left) {
                q.push(make_pair(frontnode->left, hd-1));
            }

            // Right child
            if(frontnode->right) {
                q.push(make_pair(frontnode->right, hd+1));
            }
        }

        // Map automatically stores HD in sorted order
        for(auto i : topnode) {
            ans.push_back(i.second);
        }

        return ans;
    }