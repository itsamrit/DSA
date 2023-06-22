DP ON Comparision of STRINGS (Comparision between two or more strings or vectors)   eg wildcard matching, lca, edit distance etc

int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){ 
        if(i==0||j==0)return 0;    // Base condition
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])return dp[i][j] = 1+f(i-1,j-1,s,t,dp);   // 🟩LRS:Longest repeting subsequence of an arr : aabbdd =3 abd coming 2times: s=t=arr; lcs(s,t) with restriction i!=j in 1st code of this file like if(s[i-1]==t[j-1] && i!=j).....
        else dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));                 
        return dp[i][j];
}
int lcs(string s,string t){
        int n=s.size(),m=t.size(); 
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t,dp);   
}


//🟩Special attention required : LONGEST COMMON SUBSTRING
int ans;
int dfs(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
        if(i>=nums1.size() || j>=nums2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        dfs(nums1,nums2,i+1,j,dp);
        dfs(nums1,nums2,i,j+1,dp);
        if(nums1[i]==nums2[j]){
            int k=dfs(nums1,nums2,i+1,j+1,dp);
            ans=max(ans,k+1);
            return dp[i][j]=k+1;
        }
        return dp[i][j]=0;
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
        ans=0;
        vector<vector<int>>dp(nums1.size()+3,vector<int>(nums2.size()+3,-1));
        dfs(nums1,nums2,0,0,dp);
        return ans;
}



Tabulation:
int lcsubstring(string s,string t){
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       //for(int j=0;j<=m;j++)dp[0][j]=0;
        //for(int i=0;i<=n;i++)dp[i][0]=0;
                                                                                    // For substring : int substring=0; to check at each step like recursion.
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){                                               //To checking if whole X can be suubsquence of Y
                        if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];                   //For total no of occur of X in Y as subsequence : dp[i][j]=dp[i][j-1]+dp[i-1][j-1]
                        else dp[i][j]=max(dp[i-1][j]/*remove*/,dp[i][j-1]/*insert*/; //For total no of occur of X in Y as subsequence : dp[i][j]=dp[i][j-1];
                 }
         }
         return dp[n][m];                               
}


// Backtracking:
int i=m,j=n; string s;
while(i>0 && j>0){
    if(X[i-1]==Y[j-1]){s.push_back(X[i-1]);i--;j--;}
    else if(dp[i][j-1]>dp[i-1][j])j--; //For shortest common superseq : s.push_back(X[j-1]; j--;
    else i--;                          //For shortest common superseq : s.push_back(Y[i-1]); i--;
}
reverse(s.begin(),s.end());



// Shortest common superseq i,e shortest sequence from which we can obtain both x & y by deleting some element = x.size()+y.size()-longest common subsequence
// LPS:Longest palindromic subsequence of an arr : x=a & y=reverse(a);  lcs(x,y)    
//      Follow up que: Min no insertion and deletion to make string palindrom : no of insertion = no of deletion = s.size()-lps(s)
// LRS:Longest repeting subsequence of an arr : aabbdd =3 abd coming 2times: s=t=arr; lcs(s,t) with restriction i!=j in 1st code of this file like if(s[i-1]==t[j-1] && i!=j).....
// Check if x is a subsequence of y : if(lcs(x,y)==x.size()) cout<<"yes"; 
// Min insertion, deletion to make string x to y : U dont actually insert, delete or replace a char, u just assume char inserted, deleted or replaced
//                                if a char is inserted in string s to make s[i] & t[j] equal then we assume char inserted before i & add cost of insertion like 1+dfs(i,j+1,..)
