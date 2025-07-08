class Solution {
    int delr[4] = {1,0,-1,0};
    int delc[4] = {0,-1,0,1};
    void dfs(int r,int c,vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        grid[r][c] = 0;
        for(int i=0; i<4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                dfs(nr,nc,grid);
            }
        }
        
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid1[i][j]==0 && grid2[i][j]==1){
                    dfs(i,j,grid2);
                }
            }
        }
        
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]==1){
                    dfs(i,j,grid2);
                    ans++;
                }
            }
        }
        return ans;
    }
};