 void createmapping(vector<int> in, map<int,int>& nodetoindex, int n) {

        for(int i = 0; i < n; i++) {
            nodetoindex[in[i]] = i;
        }
    }

    Node* solve(vector<int> in, vector<int> post, int &index,
                int inorderstart, int inorderend,
                int n, map<int,int>& nodetoindex) {

        // base case
        if(index < 0 || inorderstart > inorderend) {
            return NULL;
        }

        // create a root node for element
        int ele = post[index--];
        Node* root = new Node(ele);

        // find element index in inorder
        int position = nodetoindex[ele];

        // recursive call
        root->right = solve(in, post, index,
                            position + 1, inorderend,
                            n, nodetoindex);

        root->left = solve(in, post, index,
                           inorderstart, position - 1,
                           n, nodetoindex);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {

        int n = inorder.size();
        int postorderindex = n - 1;

        map<int,int> nodetoindex;

        // create nodes to index mapping
        createmapping(inorder, nodetoindex, n);

        Node* ans = solve(inorder, postorder, postorderindex,
                          0, n - 1, n, nodetoindex);

        return ans;
    }