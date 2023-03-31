Next greater element or Larget possible number from string maintains the stack as monotonically increasing.Each element of stack is smaller than prev element in next greater

string removeDuplicateLetters(string s) {
        unordered_map<char,int>vis;
        unordered_map<char,int>last;
        for(int i=0;i<s.size();i++){
            last[s[i]]=i;
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(vis[s[i]]==1)continue;
            while(ans.size() && ans[ans.size()-1]>s[i] && last[ans[ans.size()-1]]>i){
                vis[ans[ans.size()-1]]--;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i]]++;
        }
        return ans;
}
