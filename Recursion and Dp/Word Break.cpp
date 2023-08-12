🟩🟩U need to cross match all words of dictionary to all words formed from string 
// More similar problems to word break : Extra Characters in a String
// Method 2 : You just need to match all words with all dictionary.  So instead of searching each string in dictionary , you can do vice versa.
//     🟩In dp there is no optimization that u start from smallest or largest word. Start from anywhere, u need to cross match all words of dictionary to all words formed from string and find min or max or whatever is asked.
    
    set<string>st;
    vector<int>dp;
    int dfs(string &s,int c){
        if(c>=s.size())return 0;
        if(dp[c]!=-1)return dp[c];
        int mini=INT_MAX;
    
        for(int i=c;i<s.size();i++){
            if(st.find(s.substr(c,i-c+1))!=st.end()){
                mini= min(mini,dfs(s,i+1));
            }
        }
        
        return dp[c]=min(mini,1+dfs(s, c+1));
    }

    bool wordBreak(string s, vector<string>& d) {
        for(int i=0;i<d.size();i++){
            st.insert(d[i]);
        }
        dp.resize(s.size()+1, -1);
        if(dfs(s,0)>0)return false;
        return true;
    }
