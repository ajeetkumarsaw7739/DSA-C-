 // Function to detect cycle using BFS
    bool iscyclebfs(int src, unordered_map<int, bool> &visited,vector<vector<int>>& adj) {

        // Store the parent of each node
        unordered_map<int, int> parent;

        // Source node ka parent nahi hai
        parent[src] = -1;

        // Source node ko visited mark karo
        visited[src] = true;

        // BFS ke liye queue
        queue<int> q;
        q.push(src);

        // Jab tak queue empty nahi hoti
        while (!q.empty()) {

            // Queue ke front node ko nikalo
            int front = q.front();
            q.pop();

            // Current node ke saare neighbours traverse karo
            for (auto neighbour : adj[front]) {

                // CASE 1: Neighbour visited hai aur parent nahi hai
                // Iska matlab cycle present hai
                if (visited[neighbour] &&
                    neighbour != parent[front]) {

                    return true;
                }

                // CASE 2: Neighbour abhi visited nahi hai
                else if (!visited[neighbour]) {

                    // Neighbour ko queue mein add karo
                    q.push(neighbour);

                    // Neighbour ko visited mark karo
                    visited[neighbour] = true;

                    // Current node ko neighbour ka parent banao
                    parent[neighbour] = front;
                }
            }
        }

        // Cycle nahi mili
        return false;
    }

    bool isCycle(vector<vector<int>>& adj) {

        // Disconnected graph ko handle karne ke liye
        unordered_map<int, bool> visited;

        // Har connected component ko check karo
        for (int i = 0; i < adj.size(); i++) {

            // Agar node visited nahi hai, BFS start karo
            if (!visited[i]) {

                bool ans = iscyclebfs(i, visited, adj);

                // Kisi bhi component mein cycle mil gayi
                if (ans == true) {
                    return true;
                }
            }
        }

        // Kisi bhi component mein cycle nahi mili
        return false;
    }