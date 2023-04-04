```
Next greater element or Larget possible number from string maintains the stack as monotonically increasing.Each element of stack is smaller than prev element in next greater

Famous problems :-

🟩Score of Parentheses :-
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A


 int scoreOfParentheses(string s) {
        int d=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                d++;
            }
            else{
                d--; 
                if(i!=0 && s[i-1]=='('){
                    ans+=pow(2,d); //take score of all upper nested ((( && coming ))) attached to its
                }
                //else its score is already included into ans as we take whole score of upper nested while finding lowest level () 
            }
        }
        return ans;
}


🟩Remove All Adjacent Duplicates in String Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"

use stack<pair<char,int>>st; & run for loop & if current char is same as previous update count of top & else if st.push(new char) && now check if(st.top==k) pop 
