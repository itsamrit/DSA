// ✅✅If subarray can become valid(according to problem) again by adding more characters ,i,e, we cant use 2 pointer(sliding window) i,e cant move left pointer as addition of more charaters can make it valid again
// ✅ eg : target =4 and sliding window got sum 6 but still we cant move left pointer since a negative no may come -2 and sum become from current i to -2 as 4
// ✅Except SUM QUESTIONS AND VARIABLE SLIING WINDOW are takes o(n^2) time

Tc=o(nlogn)
// If asked you need to select k element from left end or right end of array such that its sum is max then ans= total sum of array - subarray with min sum of k elements
// This works for both pos and neg while sliding works only for positive
// We can print all subarrays for given sum if array does not contain 0 and negative values
NOTE: In subarray if(find(sum-target)), while in 2sum if(find(target-sum))
    
int lenOfLongSubarr(int arr[],  int n, int k) {    
    map<int, int>m;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(sum) == m.end())                 // Stores the leftmost index to maximize.   For min: store rightmost elem: always  : so dont use if here 
            m[sum] = i;
        sum += arr[i];
        if (m.find(sum - k) != m.end())                               
            if (maxLen < (i + 1 - m[sum - k]))
                maxLen = i + 1 - m[sum - k];           //For Index of largest subarray : if(..) m[sum-k] to i;
        
    }
    return maxLen;
} 


Total:Both for pos and neg elements
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        map<int,int> m;
        int cnt = 0; 
        for(int i=0;i<nums.size();i++){
            m[sum]++;
            sum += nums[i];
            if(m.find(sum-k)!=m.end())
                cnt += m[sum-k];  // presence of sum-k represent that k sum subarray is present ending at this element such that   (subarray from 0 index to somewhere in middle)sum-k  + (subarray from somewhere in middle to current index)k = sum  
        }
        return cnt;
    }

    //Total subarray divisible by k 
    for(int i = 0; i < A.size(); i++) {
            m[sum]++;
            sum = (sum + A[i]) % K; 
            if(sum<0) sum+=K; 
            if(m.find(sum)!=m.end())
               cnt += m[sum]; 
    }
