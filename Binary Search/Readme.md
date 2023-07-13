```
🟢Inclusive binary serc algo i,e if start or end are target then it has abilty to find them. 

For that inclusivity,Specify the target u are searching for all edge cases.

while(start<=end) //(<= : To also check left & right instead of only checking index betw them INCLUSIVITY)

if((mid>0 && nums[mid-1]<nums[mid]))   //🟢define target for edge cases such that while writing else if & else we are damn sure its not mid i,e write else if mid-1 & mid+1


else if() r=mid-1;  

else l = mid+1;


🟢 Always break or return when target found
Writing an algo by not returning/breaking when target found & assuming its loop will stop when target found & then RETURN MID after loop ends cause many severe edge case problem

🟢For upper bound/lower bound

if(target==nums[mid] with no same element after that i,e edge case) 

else if(target==nums[mid]) mid--/++;  //🟢Doing mid-- doesnt take o(n) it again in next iteration gives mid=start+end-.. 

else if(>) s=mid-1;

else e=mid+1;

👉while(left<=right) mid=(left+right)/2  =  left + (right-left)/2 [both are totally same in all cases][used for int overflow];

👉Universal truth = upper - lower = no of elements present of given value

👉lower_bound(v.begin(),v.end(),val) gives index of 1st occurence of val if present

👉upper_bound gives last occurence + 1 index if present otherwise upper & lower bound gives any random index but universal truth is true here as well
