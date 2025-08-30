class Solution {
    vector<vector<int>> vis;
    vector<int> ans;
    vector<pair<int,int>> qr;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    int n,m;
    int cnt = 0;

    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,-1,0,1};

    void dfs(int r,int c, vector<vector<int>>& grid, int q){
        vis[r][c] = 1;
        cnt++;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(vis[nr][nc]) continue;
                if(q > grid[nr][nc]){
                    dfs(nr,nc,grid,q);
                } else {
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m,0));
        ans.assign(queries.size(), 0);
        qr.clear();
        while(!pq.empty()) pq.pop();
        cnt = 0;

        for(int i=0;i<queries.size();i++) qr.push_back({queries[i], i});
        sort(qr.begin(), qr.end());

        pq.push({grid[0][0], 0, 0});

        for(auto &qpair : qr){
            int qval = qpair.first;
            // process ALL frontier cells whose value < qval
            while(!pq.empty()){
                auto [val, r, c] = pq.top();
                if(val >= qval) break;         // nothing more < qval
                pq.pop();
                if(vis[r][c]) continue;       // skip duplicates
                dfs(r, c, grid, qval);
            }
            ans[qpair.second] = cnt;
        }
        return ans;
    }
};
