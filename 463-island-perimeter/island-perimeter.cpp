class Solution {
    int delr[4] = {1,0,-1,0};
    int delc[4] = {0,-1,0,1};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(),m = grid[0].size();
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c]==0) continue;
                for(int i=0; i<4; i++){
                    int nr = r + delr[i];
                    int nc = c + delc[i];
                    if(nr<0 or nr>=n or nc<0 or nc>=m or grid[nr][nc]==0) ans++;
                }
            }
        }
        return ans;
    }
};