class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int>row(n,0),col(m,0);
        int tot = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) {
                    row[i]++;
                    col[j]++;
                    tot++;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && row[i]==1 && col[j]==1) {
                    cnt++;
                }
            }
        }
        return tot-cnt;
    }
};