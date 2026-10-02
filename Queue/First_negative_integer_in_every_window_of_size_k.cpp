vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        deque<int>dq;
        vector<int>ans;
        
        //process first window of k
        for(int i=0;i<k;i++){
            if(arr[i] < 0){
                dq.push_back(i);
            }
        }
        //push ans for first window
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        //now preocess for remaining window
        for(int i=k;i<arr.size();i++){
            //first pop out of window element
            if(!dq.empty() && (i-dq.front() >= k)){
                dq.pop_front();
            }
            //then push current element
            if(arr[i] < 0){
                dq.push_back(i);
            }
            //put in ans 
            if(dq.size() > 0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }