class Solution {
public:
    int delr[4] = {1, 0, -1, 0};
    int delc[4] = {0, -1, 0, 1};

    int minMoves(vector<string>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (mat[0][0] == '#') return -1;

        // Teleport positions per letter
        vector<vector<pair<int,int>>> telp(26);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                char c = mat[i][j];
                if (c >= 'A' && c <= 'Z')
                    telp[c - 'A'].emplace_back(i, j);
            }

        // 0-1 BFS: state = (row, col, mask)
        using State = tuple<int,int,int,int>;
        int maxMask = 1 << 26;
        // dist[row][col][mask] large, but we use 2D dist and clear teleports once
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<State> dq;

        dist[0][0] = 0;
        dq.emplace_front(0, 0, 0, 0);

        while (!dq.empty()) {
            auto [r, c, mask, d] = dq.front();
            dq.pop_front();
            if (d > dist[r][c]) continue;
            if (r == n - 1 && c == m - 1) return d;

            // Teleportation (cost 0)
            if (mat[r][c] >= 'A' && mat[r][c] <= 'Z') {
                int idx = mat[r][c] - 'A';
                if (!(mask & (1 << idx))) {
                    int newMask = mask | (1 << idx);
                    for (auto& [nr, nc] : telp[idx]) {
                        if (d < dist[nr][nc]) {
                            dist[nr][nc] = d;
                            dq.emplace_front(nr, nc, newMask, d);
                        }
                    }
                    // Prevent re-teleporting on this letter
                    telp[idx].clear();
                }
            }

            // Adjacent moves (cost 1)
            for (int i = 0; i < 4; ++i) {
                int nr = r + delr[i], nc = c + delc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (mat[nr][nc] == '#') continue;
                if (d + 1 < dist[nr][nc]) {
                    dist[nr][nc] = d + 1;
                    dq.emplace_back(nr, nc, mask, d + 1);
                }
            }
        }
        return -1;
    }
};
