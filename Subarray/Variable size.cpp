// ✅✅Once window becomes invalid make it valid by inner loop which deletes leftmost element till it again becomes valid as per question

// ✅✅If a question becomes again valid by adding left element then it cant be solved by sliding window.Solve it by recursion.
//         eg: Substring with frequency of each character atleast k. acca & k=2.If we delete a & then go further then it agains become valid if we add a in cca.
//         eg: Subarray with sum 0 with negative element cant be solved using sliding window because negative again become positive and make 0.

// Unique elements longest or total subarray

// Longest substring with all unique elements i,e j-i unique(fixed) characters if size of substring is k then all k must be different characters
TC=o(nlogn)
int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        map<char,int>m;
        int mx=0;
        while(j<s.size()){
            m[s[j]]++;   
            while(m.size()<j+1-i && i<s.size()){   //✅while(invalid keep deleting leftmost element)        //For Longest substring with k unique char i,e chars can repeat: while(m.size()>k) :while(unique char>k)
                    m[s[i]]--;
                    if(m[s[i]]==0)m.erase(s[i]);
                    i++;
            }
            if(m.size()==j-i+1)mx=max(mx,j+1-i);                                 //For longest substring with k unique char: if(m.size()==k)
                                                                                 //TotalSubarrays with k unique char += (j-i+1);
            j++;
        }
        return mx;                                                               //For longest substring with k unique char: if(mx>=k)return mx; else return -1;
        //return totalsubarrays with k unique char;
}



// MINIMUM WINDOW SUBSTRING  :  Give a substring of s such that every character in t(fixed) is included in that substring

string minWindow(string s, string t) {
        int m=s.size(), n=t.size();
        map<char, int> mp;
        
        for(auto x:t)  mp[x]++;
        
        int count = mp.size();
        int i = 0, j = 0 , start=0 , ans=INT_MAX;  // ans means length of required substring.

        while (j < s.length()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) count--;
 
            while (count == 0) {         // Till all element of t are present in current substring with respected amount of frequecies
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    }
                    mp[s[i]]++;         // Removing elements of s from left
                    if (mp[s[i]] > 0)   // if any 1 frquency of any element of t becomes less
                        count++;
                    i++;
            }
            
            j++;
        }
        if (ans != INT_MAX) return s.substr(start, ans);
        else return "";
}
