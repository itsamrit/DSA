👉WE COMPARE MID WITH RIGHTMOST ELEMENT while serching pivot element in rotated sorted array. NO USE OF LEFT element.

👉while(left<=right) mid=(left+right)/2  =  left + (right-left)/2 [both are totally same in all cases][used for int overflow];

👉Universal truth = upper - lower = no of elements present of given value

👉lower_bound(v.begin(),v.end(),val) gives index of 1st occurence of val if present

👉upper_bound gives last occurence + 1 index if present otherwise upper & lower bound gives any random index but universal truth is true here as well
