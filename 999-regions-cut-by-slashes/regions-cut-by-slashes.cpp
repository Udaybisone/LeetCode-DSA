class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<char>>& grid) {
        int N = grid.size();
        if (r < 0 || c < 0 || r >= N || c >= N || grid[r][c] != ' ')
            return;

        grid[r][c] = '#'; // mark as visited
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            dfs(nr, nc, grid);
        }
    }

public:
    int regionsBySlashes(vector<string>& g) {
        int n = g.size();
        int N = n * 3;
        vector<vector<char>> grid(N, vector<char>(N, ' '));

        // Fill grid with slashes using 3x3 expansion
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                int r = i * 3;
                int c = j * 3;
                char ch = g[i][j];
                if (ch == '/') {
                    grid[r][c + 2] = '/';
                    grid[r + 1][c + 1] = '/';
                    grid[r + 2][c] = '/';
                } else if (ch == '\\') {
                    grid[r][c] = '\\';
                    grid[r + 1][c + 1] = '\\';
                    grid[r + 2][c + 2] = '\\';
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == ' ') {
                    dfs(i, j, grid);
                    regions++;
                }
            }
        }
        return regions;
    }
};
