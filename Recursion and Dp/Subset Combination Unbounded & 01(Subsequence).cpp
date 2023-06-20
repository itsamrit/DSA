// if(i==nums.size()){ans.push_back(temp);return;} dont use i>nums.size return otherwise when i==nums.size  temp.push_back(nums[i]) error
// In min no of coins val[i] becomes 1 forever
// ✅✅✅This recursion is not only for combination it can be used for any  2 choices like printing all words formed by taking 1 time letter as upper case and another time as lowercase
// Start from n-1 for normal subset printing problems & -1 everthing accordingly.
// U can start recursion from n-1 for printing all subsets for simplicity because u wont be able to convert that recursive code in dp.
// ✅If u printing all combinations of array if(ind==n)ans.push_back(temp); all 1 digits to n digits combinations will be added
// ✅IF u are printing all combinations having 3 or k digits then if(ind>k){ans.push_back(temp); return;} dont forget to return otherwise same things will be printed as dfs having no push_back will be called and if(ind>k)same thing printed many times

// ✅If asked to return no of subsequences in a string which is equal to given in a vector<string>v. Check each word of v . SO tc=o(n^2) instead of checking each subsequnce o(2^n)




    vector<vector<int>>ans;
    void dfs(vector<int>&nums,int i,vector<int>&temp){
        // if(i>nums.size())return;
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        dfs(nums,i+1,temp);
        temp.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1])i++;   //🟩 For avoiding duplicates in 01 
        dfs(nums,i+1,temp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        dfs(nums,0,temp);
        return ans;
    }



int f(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){
    if(wt==0)return 1;                 //Boundry conditions   //For max/min value return 0; Think if wt is 0 max we can have 0 while if wt=0, total ways is 1 
    if(ind<0)return 0;                 //Boundry conditions
    if(ind == 0 || W==0 )return 0;            //Base condition But in unbounded : if(ind==0||W==0) return (W==0)?0:INT_MAX;
    
    if(dp[ind][W]!=-1) return dp[ind][W];
    
    dp[ind][W]=INT_MIN;
    dp[ind][W] = max(dp[ind][W] , f(wt,val,ind-1,W,dp)); 
    if(W>=wt[ind-1])                                  //Boundry conditions
        dp[ind][W] = max(dp[ind][W] , val[ind-1]+f(wt,val,ind-1,W-wt[ind-1],dp));  // for unbounded  : f(ind ,W..) 
        
    return dp[ind][W];
}


int solve(vector<int> wt, vector<int> val, int n, int W) {
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    return f(wt, val, n, W, dp);
}


Tabulation:

int f(vector<int>wt,vector<int>val,int n,int maxWeight){
     vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));
     
     for(int ind=0;ind<=n;ind++){
          for(int W=0;W<=maxWeight;W++){
               if(W==0) dp[ind][W]=1;    // Think yourself according to question
               else if(ind==0) dp[ind][W]=0;
               else {
                   dp[ind][W] = INT_MIN;  // always write else
                   dp[ind][W] = max(dp[ind][W], dp[ind-1][W]);  
                   if(W>=wt[ind-1])
                      dp[ind][W] = max(dp[ind][W], val[ind-1] + dp[ind-1][W-wt[ind-1]]); //dp[ind][..] for unbounded
               }
           }
     }
     return dp[n][maxWeight];
}

//First sort the array in main
    void Solve(vector<int>& candidates, int target, int sum, vector<vector<int>>& output, vector<int>& ans, int index){
        if(target == sum){
            output.push_back(ans);
            return;
        }
        if(candidates.size() == index)
            return;
        if(sum > target)
            return;
        ans.push_back(candidates[index]);
        Solve(candidates, target, sum + candidates[index], output, ans, index + 1);
        ans.pop_back();
        while(index < candidates.size()-1 && candidates[index] == candidates[index + 1])  //🟩ALways i<candidates with greater i+1 comparision in this
            index++;
        Solve(candidates, target, sum, output, ans, index + 1);
    }
// Target Sum : No of ways in which we can get target by applying +- in elements : call the dfs with sum+nums[i] & another time sum-nums[i]


//No of subsets for given sum     [note: Number of permutations is not equal to number of combinations but permutations with max/min sum = combination with max/min sum = subsequence with max/min sum ]
//For min diff between 2 subset of a set : do the dp & then run a loop (j=sum/2 to 0) to find greatest j whose sum is present
// Combination : Order of elements arranged doesnt matters. So same elements with different arrangement doesnt come again.        Permutation: Order matters
// eg : DP : no of combination of unbouded coins [1,2] suming 4 = 3   (1111 112 22)




// Rule : For bounded: If elements of input array may have same elements eg: 112, u cant remove them like , u have to necessarily use if(i>c && cand[i]==cand[i-1])continue; i,e 112 will be formed only 1 time in combination
//         eg:If frequency of element given(how much times elements has occured) it comes under bounded & use if(i>c&&..) to avoid duplicates
// Rule : For unbounded: All elements must be necessarily be unique. No question till now of unbounded asked with similar elements but if asked remove duplicate elements before recursive code.
//         eg: comb of unbounded [1,1,2] remove all same elements before running unbounded comb recursive code i,e it becomes unbounded comb of [1,2]
