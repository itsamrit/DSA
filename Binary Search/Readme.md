🟢Inclusive binary serc algo i,e if start or end are target then it has abilty to find them. 

For that inclusivity,Specify the target u are searching for all edge case if its inddex i,e like 

if((mid==0 || nums[mid-1]<nums[mid]))   //define target for edge cases such that while writing else if & else we dont are sure its not mid i,e write mid-1 & mid+1

else if() r=mid-1;  

else l = mid+1;

👉while(left<=right) mid=(left+right)/2  =  left + (right-left)/2 [both are totally same in all cases][used for int overflow];

👉Universal truth = upper - lower = no of elements present of given value

👉lower_bound(v.begin(),v.end(),val) gives index of 1st occurence of val if present

👉upper_bound gives last occurence + 1 index if present otherwise upper & lower bound gives any random index but universal truth is true here as well
