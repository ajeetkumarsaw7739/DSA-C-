vector<int> topoSort(vector<vector<int>>& adj) {
    
        //find all indegree
        vector<int>indegree(adj.size());
        
        for(auto i : adj){
            
            for(auto j : i){
                
                indegree[j]++;
            }
        }
        
        // 0 indegree walo ko push kardo
        
        queue<int> q;
        
        for(int i=0;i<adj.size();i++){
            
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // do bfs
        vector<int> ans;
        
        while(!q.empty()){
            
            int front = q.front();
            q.pop();
            
            //ans store
            ans.push_back(front);
            
            //neighbour indegree update
            for(auto neighbour : adj[front]){
                
                indegree[neighbour]--;
                
                if(indegree[neighbour] == 0){
                    
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }