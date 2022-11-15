👉 Common error : See if u are not returning same thing when wrong ans as well as right ans. eg :if(i>arr.size())return 0; if(k==n)return 0;

Return count of index with value 1 if u reach grid[n-1][n-1] .  if(i=n-1 && j=n-1)return 0;  if(i>n ||j>n)return INT_MIN;  return max(1+dfs()...) so that adding 1  cant improve iNT_MIN

👉 Tle : If in a arr u can move forward as well as backward then mark arr[i]=-1 when visiting like u mark in graph. Otherwise tle.

👉 Tle after memoization: You must have 1 or more parameters which is useless.

Avoid using return type bool in recursion/memoization 

For problems like return true if alleast k can be placed : Find atlmost things which can be placed using int dfs() & return true if(dfs()>=k). Similarly for atmost k.

Since you we use extra parameter for counting in bool & in int return type, return type itself gives count.

eg : Return true if robbers can rob k adjacent houses : 

Dont do:- bool dfs(int i,int cnt) if(cnt==k)return true. //2 parameters o(n^2)

Find max house which can be robbed. & in int main() if(dfs()>k) return true;

Do :- int dfs(int i) if(i==arr.size())return 0;   int canROb= 1 + dfs(); int cantRob=dfs(); return canROb+cantRob;   // 1 parameter o(n)



👉We cant apply dp only while printing

👉For count of subset if(subset with given conditions)return 1;
if(boundry condition crossed)return 0;

👉For bool memoization use int for : if(dp[i]!=-1)

✅✅1d or 2d dp is determined by no of variable parameters in void dfs(....)

✅✅Count of all incresing(length not specified) can be done using memoization but count of longest (length fixed) can be done using tabulation only.


✅✅Backtracking is done same way in both memoization & tabulation. First run dp & then run another loop to backtrack the dp vector.

✅✅Whenever u are writing code for matrix which can go more than 2 directions u need to maintain a visited matrix like u do in graph.[Endless loop i,e Stackoverflow Error]

eg: In memoization: dfs(nums,dp);   while(..)loop for backtracking.

In tabulation : for(for(..)  while(..) loop for backtracking

✔✔ If not asked to print all recursion can be converted to dp











If you are doing dp i,e storing data by using non-void recursive like int, then u need to do operations after the call.

✔✔To write recursion just think mainly 2 edge case : To write base case 1st if array contains 0 elements & 

2nd to write rest think if 1 element is present in array 






👉Write boundry conditions i,e variable value either at starting or before calling recursion or half at starting & half before calling recursion. 

eg : if(i<0 && mat[i][j]==0)return;   

eg : if(vis[i]==0) dfs();

👉Write base condition i,e static value where to return something. eg: if(i==0)return 0;

👉Marking visited & backtracking for checking all possible solutions -:

  •In graph represent as adjacency && in matrix path (directions)finding list u can only mark visited in starting i,e before for loop && unmark it for backtracking to get all solutions after loop ends.
  
  Else if u will not mark firstly it will go again to its own vertex. Since for (all child)

  •In normal matrix like chessboard & in graph represented as matrix u can only mark visited inside the loop && unmark it for backtracking also inside the loop.
  
  Because if u mark it firstly outside it will check  for(i=0 to n rows) then whole 0th row will be not itracted . Since it is marked.
      
  •In rest question you can either outside loop or inside loop


👉Permutation & Matrix combinationn/permutation matrix repre asgraph does not depend on whats upper can come again  to place a thing is similar & 
but in combination & path (both matrix, graph & tree)depends on upper


👉 In comination subset eg:knapsack u need to check before calling if(wt-wiei >0) becuae erroe if push_back(temp[i]) & only 

& so u can  return in starting only on i==0 push-back + return  not if(i<0) return

👉Whenever u write int funt in binary tree all memoization & tabulation is also possibile becuae of it u need to return at last something of function like in binary tree & combination subset

