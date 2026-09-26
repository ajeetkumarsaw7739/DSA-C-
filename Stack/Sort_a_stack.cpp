void sortedinsert(stack<int>&st,int num){
        
        //base case
        if(st.empty() || (!st.empty() && st.top() < num)){
            st.push(num);
            return ;
        }
        
        int ele = st.top();
        st.pop();
        
        //recursion call
        sortedinsert(st,num);
        
        st.push(ele);
    }
    void sortStack(stack<int> &st) {
        
        //base case
        if(st.empty()){
            return ;
        }
        
        int num = st.top();
        st.pop();
        
        sortStack(st);
        
        return sortedinsert(st,num);
    }