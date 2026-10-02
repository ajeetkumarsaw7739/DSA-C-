class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        stack<int> s;
        
        // Step 1: First k elements stack me daalo
        for(int i = 0; i < k; i++) {
            
            int val = q.front();
            q.pop();
            
            s.push(val);
        }
        
        // Step 2: Stack se elements wapas queue me daalo
        while(!s.empty()) {
            
            int val = s.top();
            s.pop();
            
            q.push(val);
        }
        
        // Step 3: Remaining elements ko front se
        // rear tak rotate karo
        int t = q.size() - k;
        
        while(t--) {
            
            int val = q.front();
            q.pop();
            
            q.push(val);
        }
        
        return q;
    }
};