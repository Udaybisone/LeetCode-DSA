class Solution {
    int delr[4] = {1,0,-1,0};
    int delc[4] = {0,-1,0,1};
    void dfs(int r,int c,vector<vector<int>>&h,vector<vector<int>> &oc){
        oc[r][c] = 1;
        int n = h.size(),m = h[0].size();
        for(int i=0; i<4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !oc[nr][nc] && h[nr][nc]>= h[r][c]){
                dfs(nr,nc,h,oc);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(),m = h[0].size();

        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atl(n,vector<int>(m,0));

        for(int j=0; j<m; j++){
            dfs(0,j,h,pac);
        }
        for(int i=0; i<n; i++){
            dfs(i,0,h,pac);
        }
        for(int j=0; j<m; j++){
            dfs(n-1,j,h,atl);
        }
        for(int i=0; i<n; i++){
            dfs(i,m-1,h,atl);
        }

        vector<vector<int>>res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};