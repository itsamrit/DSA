//✅If u need to find prim min tree or dijkstra between points i,e graph not given. Then to get all possible paths/edges, make a graph with all points connected to each other with direct edges.
//          Min cost to connect all points = Min spanning tree
//✅Dis betn all pair = 1 apply this same algo but with normal queue
vi dis;
vi par;
vector<vi>path;

void bfs(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;     //Minheap : Pops out minimum first
    dis.resize(n+3,INT_MAX);
    par.resize(n+3,-1);
    
    dis[s] = 0;
    pq.push({0,s});  ✅Always put weight 1st in pair so that pq is sorted according to weight
    while (pq.size()) {
        int c=pq.top();
        pq.pop();
        for(auto i:g[c]){
            if (dis[i.first] > dis[c.second] + i.second){//IN prim's : Since its a tree we dont check dis[i.first]>i.second+ c because then it may find shortest path but with cycle.
                dis[i.first] = dis[c.second] + i.second;   
                pq.push({dis[i.first], i.first});
                                                    // To find path : par[i.first]=c;
            }
        }
    }
    
// TO FIND PATH :    
//     path.resize(n+3);
//     forr(i,0,n-1){
//         int j=i;
//         while(j!=-1){
//             path[i].pb(j);
//             j=par[j];       
//         }
//         reverse(path[i].begin(),path[i].end());
//     }
}
