// 1 transctions:-
int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            ans=max(ans,prices[i]-mini);
        }
        return ans;
}


// INFINITE TRANSACTIONS :-
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)return 0;
        int ans=0;
        for(int i=1;i<n;i++){
            if(prices[i-1]<prices[i]){
                ans+=prices[i]-prices[i-1];
            }
        }
        return ans;
}
