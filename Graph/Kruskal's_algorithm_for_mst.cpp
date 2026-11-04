
    // Step 1: Sort edges in increasing order of weight
	static bool cmp(vector<int> &a, vector<int> &b){
	    return a[2] < b[2];
	}

    // Step 2: Initially, every node belongs to its own set
	void makeset(vector<int> &parent, vector<int> &rank, int n){

	    for(int i = 0; i < n; i++){
	        parent[i] = i;  // Every node is its own parent
	        rank[i] = 0;    // Initially rank is 0
	    }
	}

    // Step 3: Find the ultimate parent (representative) of a node
    // Path Compression: Directly connect node to its ultimate parent
	int findparent(vector<int> &parent, int node){

	    if(parent[node] == node){
	        return node;
	    }

	    return parent[node] = findparent(parent, parent[node]);
	}

    // Step 4: Merge two different sets using Union by Rank
	void unionset(int u, int v, vector<int>& parent, vector<int>& rank){

	    // Find ultimate parents of both nodes
	    u = findparent(parent, u);
	    v = findparent(parent, v);

	    // Attach smaller rank tree below larger rank tree
	    if(rank[u] < rank[v]){
	        parent[u] = v;
	    }
	    else if(rank[v] < rank[u]){
	        parent[v] = u;
	    }
	    else{
	        parent[v] = u;
	        rank[u]++;  // Increase rank when both ranks are equal
	    }
	}

	int kruskalsMST(int V, vector<vector<int>> &edges) {

	    int n = edges.size();

	    // Sort all edges according to their weights
	    sort(edges.begin(), edges.end(), cmp);

	    // Create parent and rank arrays for all vertices
	    vector<int> parent(V);
	    vector<int> rank(V);

	    // Initialize DSU
	    makeset(parent, rank, V);

	    int minweight = 0;

	    // Process edges in increasing order of weight
	    for(int i = 0; i < edges.size(); i++){

	        // Get source and destination vertices
	        int u = findparent(parent, edges[i][0]);
	        int v = findparent(parent, edges[i][1]);

	        // Weight of current edge
	        int wt = edges[i][2];

	        // If both vertices have different parents,
	        // adding this edge will not create a cycle
	        if(u != v){

	            // Add edge weight to MST
	            minweight += wt;

	            // Merge both sets
	            unionset(u, v, parent, rank);
	        }
	    }

	    // Return minimum total weight of MST
	    return minweight;
	}