class Solution {
    pair<int, int> rowcol(int cnt, int n) {
        cnt--;
        int row = n - 1 - (cnt / n);
        int col = cnt % n;
        if ((n - 1 - row) % 2 == 1) {
            col = n - 1 - col;
        }
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& grid) {
        int n = grid.size();
        // moves,cnt;
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>pq;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[n-1][0] = 0;
        pq.push({0,1});
        
        while(!pq.empty()){
            auto [move,cnt] = pq.top();
            pq.pop();
            
            if(cnt==(n*n)) return move;

            for(int i=1; i<=6; i++){
                int next = cnt + i;
                if(next > n*n) continue;
                
                auto [r,c] = rowcol(next,n);
                if(grid[r][c]!=-1) next = grid[r][c];
                auto k = rowcol(next,n);
                r = k.first;
                c = k.second;
                if(dist[r][c]>move+1){
                    dist[r][c] = move+1;
                    pq.push({move+1,next});
                }
            }
        }
        return -1;
    }
};