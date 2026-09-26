void reverseStack(stack<int> &st) {
        queue<int>q;
        
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            q.push(ele);
        }
        
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            st.push(ele);
        }
    }