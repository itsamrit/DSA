// Bridges & articulation point can be only done using dfs just like dijkstra algorithm can only be done by bfs. //[Note : There is only question on articulation point & bridges of undirected graph]

int timer=0;
int dis[N];   //1st time discovery time if we start from node 0i,e starting point
int low[N];   //Updated dis[] i,e, doesnt give lowest time to react i. Used for seeing whether its updated or not low[i] is updated or not. IF low[i]>dis[c] not updated(1 time intial update) i,e only 1 path from i to c 
void dfs(int c,int p=-1){
                                           // For articulation point : int child=0;
    vis[c]=1; 
    dis[c]=timer;
    low[c]=timer;
    timer++;
    for(auto i: g[c]) {
        if(i == p) continue;
        if(vis[i]==0){
            dfs(i,c); 
            low[c] = min(low[c], low[i]);  
                                           // For articulation point : child++;
            if(low[i] > dis[c])            // It signifies that low[i] is updated only 1 time when passed from dfs i,e there is only 1 path to i & that is from c.IF updated more than 1 time low[i] not be gretaer than dis[c]. For articulation point : if(low[i]>dis[c] && p!=-1)
                bridge.pb({c,i});          // For articulation point : point[c]=1; 
        }
        else
            low[c] = min(low[c], dis[i]);      
    }
                                           // For articulation point : if(p==-1 && child>1) point[c]=1;
}
