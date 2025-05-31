class Solution {
    pair<int, int> rowcol(int cnt, int n) {
        cnt--; // Convert to 0-based index
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
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
        vector<int> dist(n * n + 1, 1e9); // 1D distance array since we care about cell numbers
        dist[1] = 0;
        pq.push({0, 1}); // {moves, cell number}

        while (!pq.empty()) {
            auto [moves, cell] = pq.top();
            pq.pop();

            if (cell == n * n) return moves;

            for (int i = 1; i <= 6; i++) {
                int next = cell + i;
                if (next > n * n) continue;

                auto [r, c] = rowcol(next, n);
                if (grid[r][c] != -1) {
                    next = grid[r][c]; // snake or ladder destination
                }

                if (dist[next] > moves + 1) {
                    dist[next] = moves + 1;
                    pq.push({moves + 1, next});
                }
            }
        }

        return -1; // unreachable
    }
};
