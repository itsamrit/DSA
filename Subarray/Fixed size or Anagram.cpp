int maxSum(int arr[], int n, int k){
    int res = 0;
    for (int i=0; i<k; i++)res += arr[i];
    int curr_sum = res;    
    for (int i=k; i<n; i++){
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    } 
    return res;
}


Find all Anagram of p in a string s  :Either use unordered_map or normal hashing 

vector<int> findAnagrams(string s, string p) {             
        vector<int> pp(26,0);
        vector<int> ss(26,0);
        vector<int> ans;
    
        for(int i=0;i<p.size();i++){
            pp[p[i]-'a']++;
            ss[s[i]-'a']++;
        }
        if(pp == ss) ans.push_back(0);
        
        for(int i=p.size();i<s.size();i++){
            ss[s[i-p.size()] - 'a']--;
            ss[s[i] - 'a']++;
            if(pp == ss) ans.push_back(i-p.size()+1);
        }
        return ans;  //Returns starting position of all anagrams. ans.size()= total no of anagrams.
}




// Sliding Window Maximum : Return a vector containing max of each window of size k
// Link : https://leetcode.com/problems/sliding-window-maximum/
// tc=0(2*n)=o(n)  because deque takes o(1) in pop and push of first and last element unlike vector/array which take o(n) in pushing & pop first element

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
		vector<int> res;
        deque<int> mq;              // Here deque store index not value
    
        for(int i=0;i<k;i++){
            while(mq.size() && nums[mq.back()] < nums[i]) mq.pop_back();   // pop if back is lesser than new element i,e nums[i]
            mq.push_back(i);
        }
        res.push_back(nums[mq.front()]);   // mq.front () always have maximum value of that window & we will maintain this in next loop
        
        for (int i=k; i<n; i++) {
            if (mq.size() && mq.front() <= i-k) mq.pop_front();      //pop if it is previous window's 1st element i,e it cant be part of current window
            while (mq.size() && nums[mq.back()] < nums[i]) mq.pop_back();   // pop if back is lesser than new element i,e nums[i]
            mq.push_back(i);  
            res.push_back(nums[mq.front()]);
        }
        
        return res;
}
