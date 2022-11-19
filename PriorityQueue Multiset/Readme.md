S


It is like sliding window we keep on adding things till condition is broken. When condition is broken we know that to again make our condition in boundry, element at top most priority which is most relevant/irrelevant(we know this either cant be or this has to be in our ans)🟢🟢🟢🟢🟢🟢(in dp i,e recursion optimized with maths, we dont know that this cant be our this has to be at any point,dp also checks all possiblity like recursion just we dont need to print it so we can optimize) element is popped out till condition is satisfied.

So we store all the options which may or maynot be used & when limit exceed or coditions broken we either choose or pop out elements based on priority

Some times conditons is satisfied in 1 pop_out like k elements withh most sum 

some times satisfied by popping till condition

multiset<int,greater<int>>st; given first element as maximum i,e like maxheap.     st.erase(st.begin())  like pq.pop()
