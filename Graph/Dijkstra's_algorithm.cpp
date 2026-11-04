vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {

        // Creation of distance array
        vector<int> dist(adj.size(), INT_MAX);

        // Creation of set (distance, node)
        set<pair<int, int>> st;

        // Initialize source
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty()) {

            // Fetch top record
            auto top = *(st.begin());

            int nodedistance = top.first;
            int topnode = top.second;

            // Remove top record
            st.erase(st.begin());

            // Traverse neighbours
            for(auto neighbour : adj[topnode]) {

                int neighbourNode = neighbour[0];
                int weight = neighbour[1];

                if(nodedistance + weight < dist[neighbourNode]) {

                    // Find existing record
                    auto record = st.find(
                        make_pair(dist[neighbourNode], neighbourNode)
                    );

                    // If record found, erase it
                    if(record != st.end()) {
                        st.erase(record);
                    }

                    // Update distance
                    dist[neighbourNode] = nodedistance + weight;

                    // Insert updated record
                    st.insert(
                        make_pair(dist[neighbourNode], neighbourNode)
                    );
                }
            }
        }

        return dist;
    }