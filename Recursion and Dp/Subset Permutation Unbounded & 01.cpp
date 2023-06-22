// Like all other dp questions all permutation except printing can be solved using adding dp
//     eg: finding no of permutations having sum equal to target (1d dp since in void dfs(..,int sum) only 1 variable sum)

void dfs(vector<int>& num, vi &vis, vi &temp, vector<vi>&ans){                                     
        if(temp.size()==num.size()){                                        
            ans.push_back(temp);
        }
        
        for(int i = 0; i < num.size(); i++){
            if(vis[i] == 0){                                             //Remove for unbounded
                if (i > 0 && num[i] == num[i-1] && vis[i-1]) return;     //Remove for unbounded
                vis[i] = 1;                                              //Remove for unbounded
                temp.push_back(num[i]);                                
                dfs(num, vis,temp,ans);                                  //😍We dont pass index c in permutation
                temp.pop_back();            
                vis[i] = 0;                                              ✅Unmark it so that element can be permuted with other things also//Remove for unbounded
            }
        }
}


// Rule : For bounded: If elements of input array may have same elements eg: 112, u cant remove them like , u have to necessarily use if(i>c && cand[i]==cand[i-1])continue; i,e 112 will be formed only 1 time in combination
//         eg:If frequency of element given(how much times elements has occured) it comes under bounded & use if(i>c&&..) to avoid duplicates
// Rule : For unbounded: All elements must be necessarily be unique. No question till now of unbounded asked with similar elements but if asked remove duplicate elements before recursive code.
//         eg: Generate Parenethesis of size n. eg: ()))(( IF we use bounded then we need to sort like (((()))). 
//           Now we can either use unounded comb/perm code for ((())) for(2times ()) or write without for loop since there are only 2 elements  
//           Note: comb of ((())) : Since elements are not unique we necessarily have to use if(i>c&& ..) & hence only 1 combinatio will be formed ((()))
