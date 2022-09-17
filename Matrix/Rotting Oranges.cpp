

int orangesRotting(vector<vector<int>>& grid) {
        int one=0,two=0,zero=0;
        
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){            ✅ Add all elements where rotting can start before running bfs
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    one++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        vector<int>a={1,0,-1,0};
        vector<int>b={0,1,0,-1};
        while(q.size()){
            int qsize=q.size();
            while(qsize--){                     ✅ Add this to get minimum time to rotten down all oranges
                pair<int,int> c=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int ii=c.first+a[i];
                    int jj=c.second+b[i];
                    if(ii<0 || jj<0 || ii>=grid.size() || jj>=grid[0].size())continue;
                    if(grid[ii][jj]==1){
                        grid[ii][jj]=2;
                        q.push({ii,jj});
                        one--;
                    }
                }      
            }
            ans++;
        }
        if(one>0)return -1;
        if(ans==0)return 0;
        return --ans;
}
