🟩🟩ONLY REMEMBER CODE OF MERGING INTERVALS .  IN merging u just need to sort 1st index not 2nd like u dont need to do this : if(arr[i][0]==arr[i+1][0])return arr[i][1]>...
  If question is of inserting intervals and array is already sorted then insertt the interval using insert() fun on right place based on itering & mainitain sorted array with first element
  Merge the intervals  starting from interval where you inserted .tc for insertion: tc=0(n/2 inserting) & 0(n/2merging) =0(n)
  
Sort the interval based on requirement either by starting index v[i][0] or ending index v[i][1] 
Create another ans vector to insert the intervals.Dont modify existing array.If ans coming you can optimize space complex by modifying


    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& neww) {
    🟩Code to insert
//         int n=in.size();
//         for(int i=0;i<in.size();i++){
//             if(in[i][0]>=neww[0]){
//                 in.insert(in.begin()+i,neww);
//                 break;
//             }
//         }
//         if(in.size()==0)return {neww};
//         if(n==in.size())in.push_back(neww);
        
        🟩Code to merge
        vector<vector<int>>ans;
        int i=0,k=-1;
        while(i<in.size()){
            if(ans.size() && ans[k][1]>=in[i][0]){  //🟩🟩Always compare with ans[k] index not with previous interval like in[i-1]>=in[i]..
                ans[k][0]=min(ans[k][0],in[i][0]);
                ans[k][1]=max(ans[k][1],in[i][1]);
            }
            else{
                ans.push_back(in[i]);
                k++;
            }
            i++;
        }
        return ans;
    }
