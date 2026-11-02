 void solve(Node* root, long long currSum, int k,
               unordered_map<long long, int>& mp, int& ans)
    {
        if(root == NULL)
            return;

        currSum += root->data;

        // Number of paths whose sum is k
        if(mp.find(currSum - k) != mp.end())
        {
            ans += mp[currSum - k];
        }

        mp[currSum]++;

        solve(root->left, currSum, k, mp, ans);
        solve(root->right, currSum, k, mp, ans);

        // Backtrack
        mp[currSum]--;
    }

    int countAllPaths(Node* root, int k)
    {
        unordered_map<long long, int> mp;

        // Empty prefix sum
        mp[0] = 1;

        int ans = 0;

        solve(root, 0, k, mp, ans);

        return ans;
    }