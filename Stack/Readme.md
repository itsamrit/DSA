```

Famous problems : 1st Next greater ,
                  2nd calculator
                  3rd type is any question where adjacent can be deleted & new adjacent formed may be deleted
                  4th type Score of Parenthesis

🟩1st type : Next greater element or Larget possible number from string maintains the stack as monotonically increasing.Each element of stack is smaller than prev element in next greater


🟩3rd type is any question where adjacent can be deleted & new adjacent formed may be deleted   :
   🟩Code changes according to question, but it can be solved in o(n)
 Remove All Adjacent Duplicates in String Input: s = "deeedbbcccbdaa", k = 3
 Output: "aa"
 use stack<pair<char,int>>st; & run for loop & if current char is same as previous update count of top & else if st.push(new char) && now check if(st.top==k) pop

ASTEROID COLLISION IS also example of this


🟩4th type : Score of Parentheses :-
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A


 int scoreOfParentheses(string s) {
        int depth=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
            }
            else{
                depth--; 
                if(i!=0 && s[i-1]=='('){
                    ans+=pow(2,depth); //take score of all upper nested ((( && coming ))) attached to its
                }
                //else its score is already included into ans as we take whole score of upper nested while finding lowest level () 
            }
        }
        return ans;
}


🟩132 pattern i,e i<j<k && arr[i]<arr[k]<arr[j] can be solved finding next smaller to left & right of all elements and then checking if any elements have both return true.

Once rejected/deleted element for current is then rejected for all other element IN NGR element which is not next greater than current cant be next greater for the rest behind it

