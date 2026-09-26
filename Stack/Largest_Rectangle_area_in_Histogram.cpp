vector<int> nextsmallerelement(vector<int>& arr,int n){
      stack<int>st;
      st.push(-1);
      vector<int>ans(n);

      for(int i=n-1;i>=0;i--){
          int curr = arr[i];

          while(st.top() != -1 && arr[st.top()] >= curr){
              st.pop();
          }

          ans[i] = st.top();
          st.push(i);
      }
      return ans;
  }
  vector<int> prevsmallerelement(vector<int>& arr,int n){
      stack<int>st;
      st.push(-1);
      vector<int>ans(n);

      for(int i=0;i<n;i++){
          int curr = arr[i];

          while(st.top() != -1 && arr[st.top()] >= curr){
              st.pop();
          }
          ans[i] = st.top();
          st.push(i);
      }
      return ans;
  }
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        
        vector<int>next(n);
        next = nextsmallerelement(arr,n);
        
        vector<int>prev(n);
        prev = prevsmallerelement(arr,n);
        
        int area = INT_MIN;
        
        for(int i=0;i<n;i++){
            int l = arr[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = l * b;
            
            area = max(area,newarea);
        }
        return area;
    }