Next greater element or Larget possible number from string maintains the stack as monotonically increasing.Each element of stack is smaller than prev element in next greater

🟩Remove All Adjacent Duplicates in String Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"

use stack<pair<char,int>>st; & run for loop & if current char is same as previous update count of top & else if st.push(new char) && now check if(st.top==k) pop 
