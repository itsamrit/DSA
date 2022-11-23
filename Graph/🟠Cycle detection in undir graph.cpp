
Undirected Cycle BFS :
bool cycle;

void bfs(int s){
    queue<pair<int,int>>q;   // For storing current node c & its parent node p
    vis[s]=1;
    q.push({s, -1});    // In bfs queue intialized first unlike dfs
     
    while(q.size()) {  
        int c = q.front().first;
        int p = q.front().second;
        q.pop();  
    
        for(auto i:g[c]){  
            if (vis[i]==0) {  
                vis[i]=1;   // In bfs vis[i] is marked here unlike dfs
                q.push({i,c});
            }
            else if(p!=i){
                cycle=true;
                return;
            }
        }
    }
}
