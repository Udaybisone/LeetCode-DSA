class Solution {
public:
    int delr[4] = {1, 0, -1, 0};
    int delc[4] = {0, -1, 0, 1};

    int minMoves(vector<string>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (mat[0][0] == '#') return -1;

        // Collect teleport positions for each letter
        vector<vector<pair<int,int>>> telp(26);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c = mat[i][j];
                if (c >= 'A' && c <= 'Z') {
                    telp[c - 'A'].emplace_back(i, j);
                }
            }
        }

        // dist and visited masks
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        // priority queue of (distance, row, col, used_mask)
        using State = tuple<int,int,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0] = 0;
        pq.emplace(0, 0, 0, 0); 

        while (!pq.empty()) {
            auto [d, r, c, mask] = pq.top();
            pq.pop();

            if (d > dist[r][c]) continue;
            if (r == n - 1 && c == m - 1) return d;

            if (mat[r][c] >= 'A' && mat[r][c] <= 'Z') {
                int idx = mat[r][c] - 'A';
                if (!(mask & (1 << idx))) {
                    int newMask = mask | (1 << idx);
                    for (auto& p : telp[idx]) {
                        int nr = p.first, nc = p.second;
                        if (d < dist[nr][nc]) {
                            dist[nr][nc] = d;
                            pq.emplace(d, nr, nc, newMask);
                        }
                    }
                }
            }

            // Standard 4-direction moves
            for (int i = 0; i < 4; ++i) {
                int nr = r + delr[i], nc = c + delc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (mat[nr][nc] == '#') continue;
                if (d + 1 < dist[nr][nc]) {
                    dist[nr][nc] = d + 1;
                    pq.emplace(d + 1, nr, nc, mask);
                }
            }
        }

        return -1;
    }
};
