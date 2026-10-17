 vector<int> mergeArrays(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        // {value, row, column}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>
        > pq;

        // Har row ka first element heap mein daalo
        for (int i = 0; i < n; i++) {
            pq.push({mat[i][0], i, 0});
        }

        vector<int> ans;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int value = temp[0];
            int row = temp[1];
            int col = temp[2];

            ans.push_back(value);

            // Same row ka next element
            if (col + 1 < m) {
                pq.push({mat[row][col + 1], row, col + 1});
            }
        }

        return ans;
    }