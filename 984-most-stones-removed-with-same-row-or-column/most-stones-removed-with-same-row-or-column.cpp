class Solution {
    map<int, set<int>> rowAdj, colAdj;
    set<pair<int, int>> vis;

    void dfs(int x, int y) {
        if (vis.count({x, y})) return;
        vis.insert({x, y});
        for (int nx : rowAdj[x]) {
            if (!vis.count({x, nx}))
                dfs(x, nx);
        }
        for (int ny : colAdj[y]) {
            if (!vis.count({ny, y}))
                dfs(ny, y);
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        // Build adjacency by row and column
        for (auto& s : stones) {
            int x = s[0], y = s[1];
            rowAdj[x].insert(y);
            colAdj[y].insert(x);
        }

        int components = 0;
        for (auto& s : stones) {
            int x = s[0], y = s[1];
            if (!vis.count({x, y})) {
                dfs(x, y);
                components++;
            }
        }

        return stones.size() - components;
    }
};
