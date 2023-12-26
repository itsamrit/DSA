// ✅✅Once window becomes invalid make it valid by inner loop which deletes leftmost element till it again becomes valid as per question

// ✅✅If a question becomes again valid by adding left element then it cant be solved by sliding window.Solve it by recursion.
//         eg: Substring with frequency of each character atleast k. acca & k=2.If we delete a & then go further then it agains become valid if we add a in cca.
//                 Done by checking all substrings using recursion.Can be optimized to o(26*slidingwindow) = o(26*n) ✅ No need to study so deep
//         eg: Subarray with sum 0 with negative element cant be solved using sliding window because negative again become positive and make 0.

// Unique elements longest or total subarray

// Longest substring with all unique elements i,e j-i unique(fixed) characters if size of substring is k then all k must be different characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

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

PYTHON CODE :
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        j = 0
        m = {}
        mx = 0

        while (j < len(s)):
            m[s[j]] = m.get(s[j], 0) + 1

            while len(m) < j + 1 - i and i < len(s):
                m[s[i]] -= 1
                if m[s[i]] == 0:
                    del m[s[i]]
                i += 1

            if len(m) == j - i + 1:
                mx = max(mx, j + 1 - i)

            j += 1
        return mx   




// MINIMUM WINDOW SUBSTRING/ Substring of string2 containig any PERMUTATION i,e all char of string1 (fixed)
https://leetcode.com/problems/minimum-window-substring/

string minWindow(string s, string t) {
        unordered_map<char,int>m1,m2;
        for(int i=0;i<t.size();i++){
            m1[t[i]]++;
        }
        int ans=INT_MAX;
        int cnt =0;
        int j=0;
        int ii=-1;
        for(int i=0;i<s.size();i++){
            m2[s[i]]++;
            if(m1.count(s[i]) && m2[s[i]]==m1[s[i]])cnt++;
                
            while(cnt==m1.size()){      //🟩 While valid unlike above problem keep updating the ans and deleting the leftmost
                if(i-j+1<ans){
                    ans=i-j+1;
                    ii=j;
                }
                m2[s[j]]--;
                if(m1.count(s[j]) && m2[s[j]]<m1[s[j]])cnt--;
                j++;
            }

        }
        if(ii==-1)return "";
        return s.substr(ii,ans);
}

// Shortest Subarray with sum at least k with array having no negative value : 👉Prefix sum of array is monotonic increasing.
//          So we dont store prefix sum & dont pop any right element to make prefix sum monotinically increasing
//          When subarray found store it in ans & then pop left element till it subarray sum becomes less than k & then again start adding right element. again found subarray store (ans=min(..)) repeat the process


https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// Shortest Subarray with Sum at Least K with array having negative value : We need to pop rightmost elements to make prefix sum monotonically increasing
                                                                            // We need basic feature of pop left most element
                                                                        // We need to store prefix sum of each index . 
                  // SO perfect data structure : deque<pair<int,int>>d;

    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,int>>d;
        long long sum=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=k)ans=min(ans,i+1);
            while(d.size() && d.back().first>sum){   // pop till queue contains only monotonically increasing prefix sum
                d.pop_back();
            }
            while(d.size() && sum-d.front().first>=k){
                ans=min(ans,i-d.front().second);
                d.pop_front();
            }
            
            d.push_back({sum,i});
        }
        if(ans!=INT_MAX)return ans;
        return -1;
    }


Practise :-
https://leetcode.com/problems/longest-repeating-character-replacement/
