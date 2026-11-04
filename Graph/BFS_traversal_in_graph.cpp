void bfs(vector<vector<int>> &adj,unordered_map<int,bool> &visited,vector<int>&ans,int node){
        
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty()){
            
            int frontnode = q.front();
            q.pop();
            
            //store front node into ans
            ans.push_back(frontnode);
            
            //traverse all neightbours of front node
            for(auto i : adj[frontnode]){
                
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        
        vector<int> ans;
        
        unordered_map<int,bool> visited;
        
        for(int i=0;i<adj.size();i++){
            
            if(!visited[i]){
                
                bfs(adj,visited,ans,i);
            }
        }
        return ans;
    }