void dfs(int node,unordered_map<int,bool> &visited,
   vector<vector<int>>& adj,vector<int>& ans){
       
       //ans store
       ans.push_back(node);
       
       //mark visited
       visited[node] = true;
       
       //hr connected node ke liye recursive call
       for(auto i : adj[node]){
           
           if(!visited[i]){
               
               dfs(i,visited,adj,ans);
           }
       }
       
   }
    vector<int> dfs(vector<vector<int>>& adj) {
        
        vector<int> ans;
        
        unordered_map<int,bool> visited;
        
        //for all nodes call dfs if not visited
        
        for(int i=0;i<adj.size();i++){
            
            if(!visited[i]){
                
                dfs(i,visited,adj,ans);
                
            }
        }
        return ans;
    }