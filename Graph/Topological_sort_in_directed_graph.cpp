 // DFS function to perform topological sorting
    void topologicalsort(int node, vector<bool>& visited,stack<int>& s,vector<vector<int>>& adj) {

        // Mark current node as visited
        visited[node] = true;

        // Traverse all adjacent nodes
        for (auto neighbour : adj[node]) {

            // If neighbour is not visited
            if (!visited[neighbour]) {

                // Recursively visit the neighbour
                topologicalsort(neighbour, visited, s, adj);
            }
        }

        // Push node into stack after visiting all neighbours
        // This ensures reverse finishing order
        s.push(node);
    }

    vector<int> topoSort(vector<vector<int>>& adj) {

        // Number of vertices in the graph
        int v = adj.size();

        // Initially, all nodes are unvisited
        vector<bool> visited(v, false);

        // Stack stores nodes in topological order
        stack<int> s;

        // Perform DFS for all components
        for (int i = 0; i < v; i++) {

            // Start DFS from an unvisited node
            if (!visited[i]) {

                topologicalsort(i, visited, s, adj);
            }
        }

        // Store the final topological ordering
        vector<int> ans;

        // Pop elements from stack to get the answer
        while (!s.empty()) {

            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }