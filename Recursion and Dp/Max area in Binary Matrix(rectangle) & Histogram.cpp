🟩🟩🟩MAX AREA IN SQUARE IS SIMPLE ITERATIVE DP USE YOUR OWN LOGIC

Stock Span :No of consecutive days for which stocks were smaller or equal to current days price = Index of current day-NGL INDEX
vector<int> NextGreaterLeft(vector<int> nums,int n){
        stack<pair<int,int>> s;  
        s.push({INT_MAX,INT_MAX});
        vector<int> res(n); 
        for(int i=0; i<n; i++){              
            while(s.size() && s.top().first() <= arr[i])  s.pop();          
                                                                                  // IF u havent intialized the stack if(!s.size()) res[i]=-1;
            res[i]=s.top().second(); //Storing index instead of value 
            s.push({arr[i],i});
        }                                                      
        for(int i=0;i<n;i++) res[i]=i-res[i];   //Index of current day-NGL INDEX
        return res;
}











Next greater or smaller to left or right


vector<int> nextLargerElementtoright(vector<int>nums, int n){
        stack<int> s;        
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){                            //For left for(i=0 to n-1)
            while(s.size() && s.top() <= nums[i]) s.pop();    //For smallest s.top()>= nums[i]
            if(!s.size()) res[i]=(-1);
            else res[i]=(s.top());
            s.push(nums[i]);
        }
        return res;
}





Remove duplicate letters to make string smallest in lexicographical order 
Input: s = "cbacdcbc"
Output: "acdb"
   
Here u are not finding nsr or anything just common sense✅✅
According to input and output decide what u need to find. 
        Here delete all elements greater than current element in right side if element which is going to be deleted is also in left of current element.
                











Rain water trapping


int solve(vector<int>& height,int n) {
           int ans = 0;
           vector<int> leftmax(n);
           vector<int> rightmax(n);
           leftmax[0] = height[0];
           rightmax[n-1] = height[n-1];
  
           for(int i=1;i<n;i++)   left[i] = max(leftmax[i-1],height[i]);   // ultimate greatest in left
           for(int i=n-2;i>=0;i--)right[i] = max(rightmax[i+1],height[i]); // ultimate greatest in right
                  
           for(int i=0;i<n;i++) ans += min(leftmax[i],rightmax[i]) - height[i];
           return ans;
}









//  Max Reactangle in Binary Matrix & Histogram.cpp


//You dont need to store nsr rather store nsr index in stack and vector
vector<int> nsr(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;      
        for(int i=n-1; i>=0; i--){
            while(st.size() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;        
}

vector<int> nsl(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;       
        for(int i=0; i<n; i++){
            while(st.size() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;        
}

//🟩For each height[i] we find max area with that height.
int MaxAreaInHistogram(vector<int>& heights) {
        int n = heights.size();        
        vector<int> left(n), right(n);
        right = nsr(heights,n);
        left = nsl(heights,n);

        int res = INT_MIN;        
        for(int i=0; i<n; i++){
            if(left[i]==-1) left[i]= -1;
            if(right[i]==-1) right[i]= n;
            
            int w = right[i]-left[i]-1;
            res = max(res,heights[i]*w);  
        }        
        return res;
}


//MaxRectangleInBinaryMatrix: THIS QUESTION SO LONG THAT IT WILL RARERLY COME IN INTERVIEWS As it uses histograms code also:-
//🟩Make reactangle into histogram where each matrix[i][j] defines height of poll from that index
int MaxAreaInBinaryMatrix(vector<vector<int>>&matrix){
        int n=matrix.size(),m=matrix[0].size();
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j])     
                  matrix[i][j] += matrix[i-1][j];

        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans, MaxAreaInHistogram(matrix[i]));   //Calculating ans for all n Histograms  //🟩Find max histogram for each level i,e row
        return ans;
}
