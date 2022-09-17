//✅✅ When u want to check all subarrays.
Tc:n^2 

TYPE 1 DP : BASED ON CHECKING EACH SUBSTRING
// Word break  & Palindrome Partitioning

int f(int i,int n,string &str,vector<int>&dp){
    if(i==n) return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i]=INT_MAX;
    
    for(int j=i;j<n;j++){
        if(palindrome(i,j,str))  // For word break : if(s.find(s.substr(i, j-i+1))!= s.end()){.. 
           dp[i]=min(dp[i] , 1 + f(j+1,n,str,dp));
     }
     return dp[i];
}

int solve(string str){
    int n=str.size();    // For word break store all words dictionary in a set<int>s 
    vector<int>dp(n,-1);
    return f(0,n,str,dp) -1;
}


Tabulation :
int solve(string str){
        int n=str.size();
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
              dp[i]=INT_MAX;
              for(int j=i;j<n;j++){    //Here i-j decide length of substring
                  if(palindrome(i,j,str)  // For word break : if(s.find(s.substr(i, j-i+1))!= s.end()){..
                      dp[i]=min(dp[i] , 1+ dp[j+1]);        
              }
         }
         return dp[0]=1;
}

                     
TYPE 2 DP: Based on length of substring.                     
Palindromic Substrings : Numbers of palindromic substrings in a string 
          
int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans = 0;
        for(int len=1;len<=n;len++){   // length of substrings  Here i-j doesnt decide length of substring it is i - (i+len+1)
            for(int i=0;i<n-len+1;i++){
                if(len==1) dp[i][i] = 1;
                else if(len==2){
                    if(s[i]==s[i+1]) dp[i][i+1] = 1;
                    else dp[i][i+1] = 0;
                }
                else if(s[i]==s[i+len-1] && dp[i+1][i+len-2]>0) dp[i][i+len-1] = 1;   //You can also find largest palindrome by this dp[i][i+len..]++;
                else dp[i][i+len-1] = 0;
                ans += dp[i][i+len-1];
            }
        }
        return ans;
}
