DP ON Comparision of STRINGS (Comparision between two or more strings or vectors)   eg wildcard matching, lca, edit distance etc

int substring;
int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==0||j==0)return 0;    // Base condition
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])return dp[i][j] = 1+f(i-1,j-1,s,t,dp); 
        else dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));                 //For substring : dp[i][j]=0;
                                                                            //For substring : f(i-1,j,s,t,dp); f(i,j-1,s,t,dp);
                                                                            //For substring : substring=max(substring,dp[i][j]);
        return dp[i][j];
}
int lcs(string s,string t){
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t,dp);   //If we take n-1,m-1 instead of n,m then it cant be converted into tabulation simply & become hectic.
}


Tabulation:

int lcs(string s,string t){
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


// Shortest common superseq = x.size()+y.size()-longest common subsequence
// Min no of insertion and deletion to make string x to string y :  insertion(x.size()-lcs)  +  deletion(y.size()-lcs)   lcs:longest common subsequence
// Min no insertion and deletion and replacement to make string x to y:EDIT DISTANCE  for..{for..
                                                                                         //if(i==0)dp[i][j]=j; 
                                                                                         //else if(j==0)dp[i][j]=i;    
                                                                                         //else if(x[i-1]==y[i-1])dp[i][j]=dp[i-1][j-1];
                                                                                         //else dp[i][j]= 1+ min(dp[i][j-1]insert,min(dp[i-1][j]remove,dp[i-1][j-1]replace));
// LPS:Longest palindromic subsequence of an arr : x=a & y=reverse(a);  lcs(x,y)    Follow up que: Min no of deletion to make array palindrom: arr.size()-lps
// Min no insertion and deletion to make string palindrom : no of insertion = no of deletion = s.size()-lps(s)
// LRS:Longest repeting subsequence of an arr : aabbdd =3 abd coming 2times: x=arr,y=arr; lcs(x,y) with restriction if(X[i-1]==Y[j-1] && i!=j).....
// Check if x is a subsequence of y : if(lcs(x,y)==x.size()) cout<<"yes"; 
// EDIT DISTANCE : Min insertion/deletion/replacement in string a to make it b. If u insert in something in a it will match a char of b so u need to check only f(i,j-1(b))
                                                                                If u delete something in a f(i-1,j)
                                                                                If u replace something in a with b f(i-1,j-1)

