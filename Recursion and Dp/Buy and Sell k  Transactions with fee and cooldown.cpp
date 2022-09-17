//You can space optimize it further but dont go too long

int f(int ind,int buy,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
	if(ind>=n || cap==0)return 0;
	if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
	if(buy) return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0, cap, prices,n, dp), 0+f(ind+1,1,cap,prices,n,dp));  //-prices[ind]+fee +f(..
	else return dp[ind][buy][cap] = max(prices[ind] + f(ind+1,1 ,cap-1,prices,n,dp), 0+ f(ind+1,0,cap,prices,n,dp));   //prices[ind]+f(ind+1+cooldown)
}	

int maxProfit(vector<int>&prices,int n,int k){
	vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
	return f(0,1,k,prices,n,dp);
}





int maxProfit(vector<int>&prices,int n,int k){
	vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
	for(int ind=n-1;ind>=0;ind--){
		for(int buy=0;buy<=1;buy++){     // You can remove this line by optimizing but tc will remain same o(n^2) as it is running only 2 times
			for(int cap=1;cap<=k;cap++){
				if(buy) dp[ind][buy][cap]=max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
				else dp[ind][buy][cap]=max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);	
			}
		}
	}
        return dp[0][1][k];
}
