

✅Shortest dis/weight when dis/weight betn all pair = 1 i,e unweighted then apply bfs with normal queue. o(n)

🟢Solve all shortest distance graph problem from 1 point with all pos weight with bfs o(n) or o(nlogn)(priority). Else if you convert in matrix it will cost u can t solve it using normal dp since normal dp move only with adjacent nodes in matrix & non cyclic So u will apply bellman ford which will cost o(n^2).

Solve all shortest dis matrix problem where u can go to adjacent movement node like diagonal,right,left with dp. If u solve using bfs it will cost u same o(n^2 + (2n)^2) or o(n^2 + (2n)^2)log(n^2) if use priority_queue . (2n)^2 edges in normal matrix going to right down. So dont use in non cyclic traversal.

If more than 2 variable in normal matrix with adjacent movement then dp will cost o(n^3).Consider bfs if possible.

🟢If in normal matrix we can move cyclic i,e like moving in all 4 directions & distance is postive then apply bfs it will take o(n^2 + (4n)^2) or o(n^2 + (4n)^2)logn^2 if use priority  which is still lower than o(2^n).

For shortest dis between 2 group of indexes like island in matrix/graph use dfs+bfs.Find all index of 1st group using dfs & intialize the bfs queue with it.

Using Dfs :U can store all index of group1 & group2 in separete vector & run loop to find dis between all pair & select smallest dis.


👉All path from source to target : just like normal matrix use dfs.

👉To convert graph codes for matrix convert for(auto &i:g[c]) to index to where u can move from current. If u can move in all 4 dir the for(int i=0 to 4).
Change 1d visited to 2d visited


👉Dis from 1source to 1destination always bfs

👉For all paths from source to destination use dfs.Bfs will be too complex.Use bfs for returning 1 single min/max path. 

👉As real bridges are always two ways & so as bridges & articulation point are always in two way i,e in undirectional graph

👉Queue or Priority queue can be applied only to undirected graph.

In topo sort g[a].push_back(b) means a can be done only after b;

![148628820-a8fe0424-35ff-41ec-9280-6b5c15820fdf](https://user-images.githubusercontent.com/86003701/150728388-6999d308-8fdd-4005-8a70-75f6112d9dea.jpg)
