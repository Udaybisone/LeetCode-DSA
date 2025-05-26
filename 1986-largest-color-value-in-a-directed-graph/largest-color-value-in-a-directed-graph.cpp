class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> dp; // dp[node][color] = max count of that color up to this node
    vector<int> vis; // 0 = unvisited, 1 = visiting, 2 = visited
    int res = 0;
    bool dfs(int node, string &colors) {
        vis[node] = 1;
        for (int nei : adj[node]) {
            if (vis[nei] == 1) return true; // cycle
            if (vis[nei] == 0 && dfs(nei, colors)) return true;
            for (int c = 0; c < 26; c++) {
                dp[node][c] = max(dp[node][c], dp[nei][c]);
            }
        }
        dp[node][colors[node] - 'a']++;
        res = max(res, dp[node][colors[node] - 'a']);
        vis[node] = 2;
        return false;
    }

public:
    int largestPathValue(string &colors, vector<vector<int>>& edges) {
        int n = colors.size();
        adj.resize(n);
        vis.assign(n, 0);
        dp.assign(n, vector<int>(26, 0));

        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (dfs(i, colors)) return -1; // cycle detected
            }
        }
        return res;
    }
};
