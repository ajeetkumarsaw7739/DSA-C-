int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        // create adjacent list
        unordered_map<int, list<int>> adj;

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // do BFS
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        queue<int> q;
        q.push(src);

        parent[src] = -1;
        visited[src] = true;

        while(!q.empty()) {

            int front = q.front();
            q.pop();

            for(auto i : adj[front]) {

                if(!visited[i]) {

                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }

        // check if destination is reachable
        if(!visited[dest]) {
            return -1;
        }

        // prepare shortest path
        vector<int> ans;

        int currnode = dest;

        while(currnode != -1) {

            ans.push_back(currnode);
            currnode = parent[currnode];
        }

        // return shortest distance
        return ans.size() - 1;
    }