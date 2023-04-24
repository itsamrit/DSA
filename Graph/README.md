✅Dfs checks all possibilities,but here is a restriction that once visited cant be visited again. So we visit a node with random possible path & after that we cant visit that node again with any other possible path.
```
  In graph where there is only one possible path from source to a node like non-cyclic undirected graph :-
    U can also use dfs to calculate shortest/longest distance since there is only one possible path i,e it is both shotest & longest. Use either bfs or dfs in this case.
```
✅Shortest dis/weight when dis/weight betn all pair = 1 i,e unweighted then apply bfs with normal queue. o(n+e) i,e check all adjacent nodes attached first & then go to next node

🟢You cant solve any graph distance problem with normal matrix dp because even if you convert it in adjaceny matrix, u can move from 1 cell to any cell having 1 in that row. So dp cant be applied. i,e solve using either priority_queue,queuue or Specilized dp for graph like bellman ford or floyd warshall

🟢Solve all shortest dis matrix problem where u can go to adjacent movement node like diagonal,right,left with dp. If u solve using bfs it will cost u same o(n^2 + (2n)^2) or o(n^2 + (2n)^2)log(n^2) if use priority_queue . (2n)^2 edges in normal matrix going to right down. So dont use in non cyclic traversal.

-> When to apply bfs in normal matrix -: 

1.If more than 2 variable in recursive function( int i,int j, int 3rd) in normal matrix even with adjacent movement i,e no cicular movement even then dp will cost o(n^3).Consider bfs,if possible.

2.If in normal matrix we can move cyclic i,e like moving in all 4 directions & distance is postive then apply bfs it will take o(n^2 + (4n)^2) or o(n^2 + (4n)^2)logn^2 if use priority  which is still lower than o(2^n).

⭐SubTopic :For shortest dis between 2 group of indexes like island in matrix/graph use dfs+bfs.Find all index of 1st group using dfs & intialize the bfs queue with it.

Using Dfs :U can store all index of group1 & group2 in separete vector & run loop to find dis between all pair & select smallest dis.

⭐SubTopic : Given 01 matrix,find nearest 0 for each cell. Store all the 0 in queue as group1 like in above problem & initalize all nodes which are in queue as 0 distance from 0 & apply normal bfs to find no of steps to go to each cell

⭐ There are many prob in which u need to store a group of nodes or start dfs or bfs from a grp of nodes.

👉All path from source to target : just like normal matrix use dfs.

👉To convert graph codes for matrix convert for(auto &i:g[c]) to index to where u can move from current. If u can move in all 4 dir the for(int i=0 to 4).
Change 1d visited to 2d visited


👉Dis from 1source to 1destination always bfs

👉For all paths from source to destination use dfs.Bfs will be too complex.Use bfs for returning 1 single min/max path. 

👉As real bridges are always two ways & so as bridges & articulation point are always in two way i,e in undirectional graph

👉Queue or Priority queue can be applied only to undirected graph.

In topo sort g[a].push_back(b) means a can be done only after b;

🟢Pacific & Atlantic Water Flow : make two vector<vector<int>> vis1, vis2 && if run dfs from all cells attached to oceans & if both visited for a cell include it in ans

🟢Dont put unnecessary return; everywhere

![148628820-a8fe0424-35ff-41ec-9280-6b5c15820fdf](https://user-images.githubusercontent.com/86003701/150728388-6999d308-8fdd-4005-8a70-75f6112d9dea.jpg)
