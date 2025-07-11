class Solution {
    int n , m;
    int delr[4] = {1,0,-1,0};
    int delc[4] = {0,-1,0,1};
    void dfs(int r,int c,vector<vector<int>>&grid,int val){
        grid[r][c] = val;

        for(int i=0; i<4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];

            if(nr>=0 && nr<n && nc<m && nc>=0 && grid[nr][nc]==1){
                dfs(nr,nc,grid,val);
            }
        }
    }


public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    if(cnt==0) {
                        dfs(i,j,grid,-1);
                        cnt++;
                    }
                    else{
                        dfs(i,j,grid,-2);
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt==2) break;
        }

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==-1){
                    pq.push({0,i,j});
                }
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(grid[i][j]==0) grid[i][j] = 1e8;
            }
        }

        while(!pq.empty()){
            auto [dist,r,c] = pq.top(); pq.pop();

            if(grid[r][c]==-2) return dist-1;

            for(int i=0; i<4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr>=0 && nr<n && nc<m && nc>=0 && grid[nr][nc]!=-1){
                    if(grid[nr][nc]==-2) pq.push({dist+1,nr,nc});
                    else if(grid[nr][nc]> dist+1) {
                        grid[nr][nc] = dist+1;
                        pq.push({dist+1,nr,nc});
                    }
                } 
            }
        }
        return -1;
    }
};