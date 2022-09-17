✅✅Dp :We can take either 1,2, or any CONSTANT no of steps irrespective of element value.
 eg : house robber tree : you need to see all adajceny possibiliy in recursion
      i,e u need to write more than normal recursion for that all constant no of steps both if adjacent takes or not
       FIbonnaci series
    ✅ If circular condition eg : housees are in circle i,e array 1st & last element adjacent .Call one recursion for 0 to num.size()-2 & another for 1 to num.size()-1
                So,that when we take 1st element we cant take last one & vice versa
                
✅✅Greedy : Element decide how many steps(VARIABLE) we can take from that point.
 eg :jump game 2 : Reach the last index in the minimum number of jumps where each elemets denotes max jump u can take from that element.
    :gas station question : Whether we can reach the required place with given fuel at each station



// [note: Number of permutations is not equal to number of combinations but permutations with max/min sum = combination with max/min sum = subsequence with max/min sum ]
// Note : Since it is unbounded no of combinations = no of permutations. eg: Unbounded combination of 1,2 doesn't mean combination of 1..∞ 2..∞ , it means combination of 1..∞,2...∞,1..∞,2..∞..∞. 
//                                                                            So ultimately their is no differnce between unbounded combination and permutation.
// Gives combination/permutation/sequence with respect to max/min cost because because while finding min/max cost u can call it combination/permutation/sequence .
// Cost is similar to knapsack which doesnt contribute to main sum.
// We need to choose between adjacent elements : dp[n] 



   eg: Paint house with min cost with any of 3 colors without having same adjacent house same colored. dp[n][3]
   // We need to choose between adjacent or 2,3 or 4 choices & 1 cost at each element : dp[n]
   eg: Max sum when we cant take 2 adjacent elements OR House Robber
       Decode ways : No of ways to decode a string given in number form to alphabet
       Ways of painting the fence such that at most 2 adjacent fences have the same color
          dp[0] = k, dp[1] = k*k;
          for(int i =2; i<n; i++) dp[i] = dp[i-1]*(k-1) + dp[i-2])*(k-1);
       Domino Tiling
       

   
// Gives total no combinations/permutations of unbounded elements when element are sequential like 1,2,3...k like n stairs & fibonnic.
// n stairs with steps 1,2,3..k(in sequential order) i,e Total combination/permutations that sum up to n with unbounded element 1,2..k(sequential)
// fibonnic : If u observe it is n stairs with step 1,2. It gives no of combination/permutation that sum up to n with element unbouned 1,2.
