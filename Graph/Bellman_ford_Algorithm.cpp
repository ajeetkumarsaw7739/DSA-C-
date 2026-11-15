 vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int> dist(V, 1e8);

        dist[src] = 0;

        // n-1 times
        for(int i = 1; i < V; i++) {

            // traverse on edge list
            for(int j = 0; j < edges.size(); j++) {

                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(dist[u] != 1e8 && (dist[u] + wt) < dist[v]) {

                    dist[v] = dist[u] + wt;
                }
            }
        }

        // check for negative cycle
        bool flag = 0;

        for(int j = 0; j < edges.size(); j++) {

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e8 && (dist[u] + wt) < dist[v]) {

                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            return dist;
        }

        return {-1};
    }