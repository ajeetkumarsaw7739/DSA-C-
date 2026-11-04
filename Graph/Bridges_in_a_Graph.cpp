
    void dfs(int node, int parent, int &timer,vector<int>& disc, vector<int>& low,
             vector<vector<int>> &result,
             unordered_map<int,list<int>> &adj,
             unordered_map<int,bool> &vis){

        // Mark current node visited
        vis[node] = true;

        // Discovery time and lowest discovery time
        disc[node] = low[node] = timer++;

        for(auto nbr : adj[node]){

            // Ignore the parent node
            if(nbr == parent){
                continue;
            }

            // If neighbour is not visited
            if(!vis[nbr]){

                dfs(nbr, node, timer, disc, low, result, adj, vis);

                // Update low value using child's low value
                low[node] = min(low[node], low[nbr]);

                // Check whether edge is a bridge
                if(low[nbr] > disc[node]){

                    vector<int> ans;
                    
                    ans.push_back(node);
                    ans.push_back(nbr);

                    result.push_back(ans);
                }
            }
            else{

                // Back edge: update low using discovery time
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d){

        // Create adjacency list
        unordered_map<int,list<int>> adj;

        for(int i = 0; i < edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 0;

        vector<int> disc(V, -1);
        vector<int> low(V, -1);

        unordered_map<int,bool> vis;

        vector<vector<int>> result;

        // Run DFS for all connected components
        for(int i = 0; i < V; i++){

            if(!vis[i]){
                dfs(i, -1, timer, disc, low, result, adj, vis);
            }
        }

        // Check whether given edge (c,d) is a bridge
        for(auto edge : result){

            if((edge[0] == c && edge[1] == d) ||
               (edge[0] == d && edge[1] == c)){
                return true;
            }
        }

        return false;
    }