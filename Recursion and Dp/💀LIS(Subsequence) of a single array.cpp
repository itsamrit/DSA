LONGEST INCREASING SUBSEQUENCE :  Generate all subsequence like subset 01 combination & take longest increasing of that.
✅Whenever previous index is a parameter in recursion then in tabulation 2nd loop i,e prev cant go beyond 1stloop i,e cur.  
        So we run for(i=0 to n){ for(j=0 to i) otherwise wrong ans will come.

int dfs(int a[],int i,int prev,int n){    //  Intialize : prev=-1
        if(i==n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    
        dp[i][prev+1]=dfs(a,i+1,prev,n);     //✅🤷‍♂️🤷‍♂️🤷‍♂️🤷‍♂️🤷‍♂️💀💀RATNA prev doesn't change RATNA
        if(prev==-1 || a[prev]<a[i]){
            dp[i][prev+1]=max(dp[i][prev+1],1+dfs(a,i+1,i,n));
        }
        return dp[i][prev+1];
}

//Binary Search : U can only find length of LIS , u cant print it & u cant find count of all LIS (tc:nlogn)

int solve(int arr[],int n){
  vector<int>temp;
  temp.push_back(arr[0]);
  for(int i=1;i<n;i++){
    if(arr[i] > temp[temp.size()-1] )
      temp.push_back(arr[i]);
    else{
      int ii = lower_bound(temp.begin(),temp.end(), arr[i] ) -temp.begin();
      temp[ii]=arr[i];
    }
  }
  return temp.size();
}
      

// Longest Bitonic Subsequence (Subsequence which first increases & then decreases) : Tabulation only by striver (same on gfg)
             Find LIS till each element of array & then find LIS of each element by reversing the array.
             Then for each element sum up their LIS of both normal array & revesed array & element having max sum has max bitonic subsequence.

NOTE : If question asked longest subset of anything firstly sort the array. Else if asked subsequence dont sort the array.
// Largest Divisible Subset (Subset whose every element are gives remainder 0 when divided a%b=0) :
            Sort the arr. Then inside code to print LIS, instead of checking if(arr[i]>arr[j] && dp..) check if(arr[i] % arr[j]==0 && dp..)

// Longest String Chain Subset(chain in which adding 1 char in prev string makes cur string): 
             Sort the array using customized compare function. In code of LIS, instead of checking if(arr[i]>arr[j] && dp..) , check if((checkpossible(arr[i],arr[j])) && dp..) ,where 
             bool checkpossible(string &s1,string &s2){
                 if(s1.size() !=s2.size()+1) return false;
                 int i=0,j=0;
                 while(i<s1.size()){
                    if(s1[i]==s2[j]){i++,j++;}
                    else i++:
                 }
                 if(i==s1.size() && j==s2.size()) return true;
                 return false; 
             }
