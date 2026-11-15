 void dfs(int node, unordered_map<int,bool>& vis,stack<int>& st, vector<vector<int>>& adj) {

        vis[node] = true;

        for(auto nbr : adj[node]) {

            if(!vis[nbr]) {
                dfs(nbr, vis, st, adj);
            }
        }

        // Topo sort logic
        st.push(node);
    }

    void revdfs(int node, unordered_map<int,bool>& vis,unordered_map<int,list<int>>& adj) {

        vis[node] = true;

        for(auto nbr : adj[node]) {

            if(!vis[nbr]) {
                revdfs(nbr, vis, adj);
            }
        }
    }

    int countSCC(vector<vector<int>>& adj) {

        // Step 1: Topological Sort
        stack<int> st;

        unordered_map<int,bool> vis;

        for(int i = 0; i < adj.size(); i++) {

            if(!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // Step 2: Create Transpose Graph
        unordered_map<int,list<int>> transpose;

        for(int i = 0; i < adj.size(); i++) {

            vis[i] = false;

            for(auto nbr : adj[i]) {
                transpose[nbr].push_back(i);
            }
        }

        // Step 3: DFS according to stack ordering
        int cnt = 0;

        while(!st.empty()) {

            int top = st.top();
            st.pop();

            if(!vis[top]) {

                cnt++;

                revdfs(top, vis, transpose);
            }
        }

        return cnt;
    }