int primMST(vector<vector<vector<int>>> &adj) {

        int n = adj.size();

        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);
        vector<int> parent(n, -1);

        // Start from node 0
        key[0] = 0;

        for(int i = 0; i < n; i++) {

            int mini = INT_MAX;
            int u = -1;

            // Find the minimum key node
            for(int v = 0; v < n; v++) {

                if(mst[v] == false && key[v] < mini) {

                    u = v;
                    mini = key[v];
                }
            }

            // Mark the selected node
            if(u == -1)
                break;

            mst[u] = true;

            // Check adjacent nodes
            for(auto it : adj[u]) {

                int v = it[0];
                int w = it[1];

                if(mst[v] == false && w < key[v]) {

                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

        // Calculate total MST weight
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += key[i];
        }

        return sum;
    }