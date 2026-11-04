 // DFS function to detect cycle in a directed graph
    bool checkcycledfs(int node,unordered_map<int, bool> &visited,unordered_map<int, bool> &dfsvisited,
                       vector<vector<int>>& adj) {

        // Mark current node as visited
        visited[node] = 1;

        // Mark current node as part of the current DFS path
        dfsvisited[node] = 1;

        // Traverse all neighbours of the current node
        for (auto neighbour : adj[node]) {

            // CASE 1: Neighbour is not visited
            if (!visited[neighbour]) {

                // Recursively check the neighbour
                bool cycledetected = checkcycledfs(neighbour, visited, dfsvisited, adj);

                // If cycle is detected in the recursive call
                if (cycledetected) {
                    return true;
                }
            }

            // CASE 2: Neighbour is already in the current DFS path
            // This indicates a cycle in the directed graph
            else if (dfsvisited[neighbour]) {
                return true;
            }
        }

        // Remove current node from the current DFS path
        dfsvisited[node] = 0;

        // No cycle found from this node
        return false;
    }

    bool isCyclic(vector<vector<int>>& adj) {

    
        unordered_map<int, bool> visited;

    
        unordered_map<int, bool> dfsvisited;

        // Check every component of the graph
        for (int i = 0; i < adj.size(); i++) {

            // Start DFS from every unvisited node
            if (!visited[i]) {

                bool cyclefound = checkcycledfs(i, visited, dfsvisited, adj);

                // If any component contains a cycle
                if (cyclefound) {
                    return true;
                }
            }
        }

        // No cycle exists in the directed graph
        return false;
    }