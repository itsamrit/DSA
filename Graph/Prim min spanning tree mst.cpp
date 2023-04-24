// 🟩MST is only possible in undirected graph .SInce tree is only undirected ascylic graph
// 🟩In dijkstra we go further in path which has lowest dis from root.To check dis from root we need to dis[i.first]>dis[c.second]+i.second;
// 🟩But in prim we check which node has shortest dis from cur node. So we dont bagge of root node so we check dis[i.first]>i.second; & include it in minheap
// tc = o((e+v)logv) because it is dijkstra algo with backtracking
vi par;
vi dis;

void prim(int s){
    par.resize(n+3,-1);
    dis.resize(n+3,inf);
    priority_queue<pii,vector<pii>,greater<pii>> pq;  //Minheap : Sorting in Ascending order
    vi vis(n+3,0);
    
    pq.push({0,s});
    dis[s]=0;

    while(pq.size()){
        int c = pq.top().second;
        pq.pop();
        if(vis[c] == 1)continue;
        vis[c] = 1;  //Once we have visited a node, we dont need to reiterate over it again
                     
        for(auto i:g[c]){
            if (vis[i.first] == 0 && dis[i.first] > i.second){  //🟩MEMOIZE : logic very hard : there is no link between parent & child distance in mst
                dis[i.first] = i.second;                          
                pq.push({dis[i.first], i.first});  
                par[i.first]=c;
            }
        }
    }
    int totalweight=0;
    forr(i,1,n-1){
        if(dis[i]==inf){cout<<"No MST because Graph is disconnected";return;}
        totalweight+=dis[i];
        cout<<i<<"connectedTo"<<par[i];
    }
}
