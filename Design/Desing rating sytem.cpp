MUST DO QUESTION TO UNDERSTAND NESTED MAP,SET, and priority queue
map<int,int> is actually set<pair<int,int>> so tc doesnt effected even if u use map 
https://leetcode.com/problems/design-a-food-rating-system/description/
Always use map instead of set and priority queue all have same time complexity 

set is use to just find whether present or not or to sort but both these can be performed by map .
map<int, set<pair<int, string>>> m; // used to find lowest or highest sorted 

map<int , map<int,string>>m;
use rbegin and rend to use descend ing order

👌When we have multiple same key and we want to search , delete a a thing and we know both key and value then,
  Since even after finding key we need to loop to search for particular value .
We use set<pair<key,value>>   or map<pair<key,value>, useless>>  not map<key,value> 
becaue we search in logn m.count({key,value})   m.erase({key,value})


💕Multiset or multimap has 1 problem u need another internal serach since there can be multiple same key
