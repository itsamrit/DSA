🟢😊 Always analyze the time complexity.
If its 10^4 or 10^5, there is high chance it uses map or set nlogn

🟢Learn the techniques of all question which method will be used so that even implementation fails,u get points

🟢For online round :

To convert int to long long : long long new= (long long)old;  & vice versa i,e int new = (int)old;

int to string : to_string(num);

string to int : stoi(str);

char to int & int to char : -'0' - 'a' respectively

Size of string is not in int when applying max,min function

(int)forbidden[i].size()

🟢Only normal queue & deque has front back
  
lexographically maximum no subset more than 10 questions with different just remember it is solved by stack

👉 for(auto &i:mapp) Use &i otherwise iterator will remain on 1st element

👉 ROWs == RECORDs while column means attributes

👉In Matrix's 4 way travelling if(vis[i][j]) return; is not tle for dfs(i-1,j) & dfs(i,j-1);

BUT once rejected/deleted element for current is then rejected for all other element
IN NGR  element which is not next greater than current cant be next greater for the rest behind it

👉Thumb rule : Always intialize the queue,stack,map etc before the doing any operation on it in loops.

👉Iterators:

for(auto i:m) i.first i.second

for(auto i=m.begin(); i!=m.end(); i++) m

👉 If 2 or more arrays or numbers in questions for comparision like A & B.

Always make 1 smaller if(A>B) swap(A,B) & then solve accordingly.

👉 Never do modulo as %10^7+7 [Error]. Instead do %1000007

👉lower_bound(v.begin(),v.end(),val) gives index of 1st occurence of val if present
