class Solution {
    pair<int,int> rowcol(int cnt,int n){
        cnt--; // convert to 0-based
        int row = n - 1 - (cnt / n);
        int col = cnt % n;
        if ((n - 1 - row) % 2 == 1) {
            col = n - 1 - col;
        }
        return {row,col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q; // {cell_number, moves}
        vector<int> visited(n*n + 1, 0);
        q.push({1, 0});
        visited[1] = 1;

        while (!q.empty()) {
            auto [cell, moves] = q.front();
            q.pop();
            if (cell == n*n) return moves;

            for (int i = 1; i <= 6 && cell + i <= n*n; i++) {
                int next = cell + i;
                auto [r, c] = rowcol(next, n);
                if (grid[r][c] != -1) next = grid[r][c];

                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
