 void dfs(int node, int parent, vector<int>& disc,vector<int>& low, unordered_map<int,bool>& vis,
             unordered_map<int,list<int>>& adj,
             vector<int>& ap, int &timer) {

        vis[node] = true;
        disc[node] = low[node] = timer++;

        int child = 0;

        for(auto nbr : adj[node]) {

            if(nbr == parent) {
                continue;
            }

            if(!vis[nbr]) {

                dfs(nbr, node, disc, low, vis, adj, ap, timer);

                // Check articulation point or not
                low[node] = min(low[node], low[nbr]);

                if(low[nbr] >= disc[node] && parent != -1) {
                    ap[node] = 1;
                }

                child++;
            }
            else {
                low[node] = min(low[node], disc[nbr]);
            }
        }

        // Special case for root node
        if(parent == -1 && child > 1) {
            ap[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {

        // Adjacency list
        unordered_map<int,list<int>> adj;

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 0;

        vector<int> disc(V);
        vector<int> low(V);

        unordered_map<int,bool> vis;
        vector<int> ap(V, 0);

        // DFS
        for(int i = 0; i < V; i++) {

            if(!vis[i]) {
                dfs(i, -1, disc, low, vis, adj, ap, timer);
            }
        }

        vector<int> ans;

        for(int i = 0; i < V; i++) {
            if(ap[i] == 1) {
                ans.push_back(i);
            }
        }

        if(ans.empty()) {
            return {-1};
        }

        return ans;
    }