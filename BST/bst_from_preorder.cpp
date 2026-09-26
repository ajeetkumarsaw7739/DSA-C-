class Solution {
  public:
    Node* solve(vector<int>& pre, int mini, int maxi, int &i) {
        
        // base case
        if(i >= pre.size()) {
            return NULL;
        }
        
        if(pre[i] < mini || pre[i] > maxi) {
            return NULL;
        }
        
        Node* root = new Node(pre[i++]);
        
        // recursion call
        root->left = solve(pre, mini, root->data, i);
        
        root->right = solve(pre, root->data, maxi, i);
        
        return root;
    }

    Node* preToBST(vector<int>& pre) {
        
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        
        return solve(pre, mini, maxi, i);
    }
};