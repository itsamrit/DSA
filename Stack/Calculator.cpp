🟢Like +- have same priority so as /* have same priority.eg: 2*3/2 .U either divide first or multiply ans will be same
👌U can, Instead of else always write else if to easily debug

https://leetcode.com/problems/basic-calculator-ii/
🟢You will be given either +-/* or +-() questions . You cant have */ and () combined and solved using stack
   In both cases we need to make number from char so there will be another while loop inside main loop
   🟢IN +-/* whenever +- comes we simply push it into stack & whenever /* comes we go back or pop 1 element and push the current element multiplied or divided by poped element.
       At last we add all elemetns of stack.

    int calculate(string s) {
        stack<int>st;
        char prev ='+';
        int i=0;
        while(i<s.size()){
            while(i<s.size() && s[i]==' ')i++;
            string temp="";
            while(i<s.size() && s[i]>='0' && s[i]<='9'){
                temp.push_back(s[i]);
                i++;
            }
            int tempp=0;
            if(temp!=""){
                tempp=stoi(temp);
                if(prev=='+'){
                    st.push(tempp);
                }
                else if(prev =='-'){
                    st.push(-1*tempp);
                }
                else if(prev == '*'){
                    st.top()*=tempp;
                }
                else if(prev == '/'){
                    st.top()/=tempp;
                }
            }
            while(i<s.size() && s[i]==' ')i++;
            if(i<s.size() && (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')){
                prev =s[i];
                i++;
            }
        }
        int ans =0;
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }

https://leetcode.com/problems/basic-calculator/
   🟢IN +-() push all element in stack and when ) comes we go back and add each element of stack till ( appers. At last we can add all elements of stack.
       Improvement : We can add each element while traversing and only push sumation of all element before ( appears & pop that top most sumation when ) appears & add it to current sum.
           
    int calculate(string s) {
        int ans =0;
        int sign=1;
        stack<int>st;
        int i=0;
       
        while(i<s.size()){
            while(i<s.size() && s[i]==' ')i++;
            string temp="";
            while(i<s.size() && s[i]>='0' && s[i]<='9'){
                temp.push_back(s[i]);
                i++;
            }
            int tempp=0;
            if(temp!=""){
                tempp=stoi(temp);
                ans += sign*tempp;
            }
            while(i<s.size() && s[i]==' ')i++;  //😊either u write this or not, no difference in output
           
            if(i<s.size() && s[i]=='+'){
                sign=1;
                i++;
            }
            else if(i<s.size() && s[i]=='-'){
                sign=-1;
                i++;
            }
            else if(i<s.size() && s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                sign =1;
                i++;
            }
            else if(i<s.size() && s[i]==')'){
                ans = ans*st.top();
                st.pop();
                ans += st.top();
                st.pop();
                i++;
            }
        }
        return ans;
    }
