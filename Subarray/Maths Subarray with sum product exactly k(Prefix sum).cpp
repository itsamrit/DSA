❤️❤️❤️EXCEPTION to following -
// ✅✅If subarray can become valid(according to problem) again by adding more characters ,i,e, we cant use 2 pointer(sliding window) i,e cant move left pointer as addition of more charaters can make it valid again
// ✅ eg : target =4 and sliding window got sum 6 but still we cant move left pointer since a negative no may come -2 and sum become from current i to -2 as 4
// ❤️❤️❤️EXCEPTION SUM QUESTIONS AND VARIABLE SLIING WINDOW are takes o(n^2) time
// ✅✅✅IF ASKED VARIABLE SIZE AND SEMI VARIABLE i,e greater than or smaller than given value with all positive elements in array then use sliding window VARIABLE SUBARRAY  
//        eg: Smallest subarray with sum greater than or equal to x
// ✅MATHS questions which cant be solved by sliding can be solved by this prefix sum. Like subarray with sum 0 with neg elements
Tc=o(nlogn)
// If asked you need to select k element from left end or right end of array such that its sum is max then ans= total sum of array - subarray with min sum of k elements
// This works for both pos and neg while sliding works only for positive
// We can print all subarrays for given sum if array does not contain 0 and negative values
   
NOTE: In subarray if(find(sum-target)), while in 2sum if(find(target-sum))
//LONGEST/SHORTEST/TOTAL SUBARRAYS WITH SUM EXACTLY K
   
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


🟢Total subarray with sum is equals k:Both for pos and neg elements
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

    //Total subarray divisible by k (DIVISIBILITY TEST : ✅Make all nums[i] in remainder form num[i]%=k; && Change all negative in pos by adding K. Since divisiblity cant be affected by pos or neg no. 
                                                        // 🟩Neg doesnt directlly convert to pos.eg -2 becomes 3 if k=5
                                                        // 🟩eg : k=5 and array = 2,-2 total subarray divisible =1 beacuase 2+-2 =0. So convert -2 to -2+k=3 && 2+3=5 divisible by 5
    for(int i = 0; i < A.size(); i++) {
            m[rem]++;
            rem = (rem + A[i]) % K; 
            if(m.find(rem)!=m.end())   //✅Here rem is remainder not sum. So if a b c are 3 subarrays in sequence & if a & c gives same remainder with k then b be having sum divisible by k 
               cnt += m[rem]; 
    }
