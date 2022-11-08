👉To convert graph codes for matrix convert for(auto &i:g[c]) to index to where u can move from current. If u can move in all 4 dir the for(int i=0 to 4).
Change 1d visited to 2d visited

👉Dis from 1source to 1destination always bfs

👉For all paths from source to destination use dfs.Bfs will be too complex.Use bfs for returning 1 single min/max path. 

👉As real bridges are always two ways & so as bridges & articulation point are always in two way i,e in undirectional graph

👉Queue or Priority queue can be applied only to undirected graph.

In topo sort g[a].push_back(b) means a can be done only after b;

![148628820-a8fe0424-35ff-41ec-9280-6b5c15820fdf](https://user-images.githubusercontent.com/86003701/150728388-6999d308-8fdd-4005-8a70-75f6112d9dea.jpg)
