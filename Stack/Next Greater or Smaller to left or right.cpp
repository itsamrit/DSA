//Next Greater Element to right

vector<int> nextLargerElementtoright(vector<int>nums, int n){
        stack<int> s;        
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){                            //For left for(i=0 to n-1)
            while(s.size() && s.top() <= nums[i]) s.pop();    //For smallest s.top()>= nums[i]
            if(!s.size()) ans[i]=(-1);
            else ans[i]=(s.top());
            s.push(nums[i]);
        }
        return ans;
}
