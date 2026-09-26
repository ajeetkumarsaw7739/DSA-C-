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
    vector<int> prevsmallerelement(vector<int>&arr,int n){
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
    int largestrectanglearea(vector<int>& height,int n){
        
        vector<int>next(n);
        next = nextsmallerelement(height,n);
        
        vector<int>prev(n);
        prev = prevsmallerelement(height,n);
        
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int l = height[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = l * b;
            area = max(area,newarea);
        }
        return area;
    
    }
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        // compute area for first now
        int area = largestrectanglearea(mat[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //row update by adding previous row value
                if(mat[i][j] != 0){
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                }
                else{
                    mat[i][j] = 0;
                }
            }
            //entire row is update now
            area = max(area,largestrectanglearea(mat[i],m));
        }
        return area;
    }