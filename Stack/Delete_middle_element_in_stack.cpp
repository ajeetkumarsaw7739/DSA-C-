 void solve(stack<int>&s,int n,int cnt){
        //base case
        if(cnt == n/2){
            s.pop();
            return ;
        }
        int num = s.top();
        s.pop();
        
        //recursive call
        solve(s,n,cnt+1);
        
        s.push(num);
    }
    void deleteMid(stack<int>& s) {
        int n = s.size();
        int cnt = 0;
        
        solve(s,n,cnt);
    }