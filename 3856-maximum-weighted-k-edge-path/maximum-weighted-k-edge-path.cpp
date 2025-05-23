class Solution {
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;

    int f(int node, int k, int sumSoFar, int t, vector<vector<pair<int,int>>>& adj) {
        if (k == 0) return 0;
        if (dp[node][k].count(sumSoFar)) return dp[node][k][sumSoFar];

        int maxsum = -1;
        for (auto [child, wt] : adj[node]) {
            int newSum = sumSoFar + wt;
            if (newSum < t) {
                int childSum = f(child, k - 1, newSum, t, adj);
                if (childSum != -1) {
                    maxsum = max(maxsum, wt + childSum);
                }
            }
        }
        return dp[node][k][sumSoFar] = maxsum;
    }

public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].emplace_back(e[1], e[2]);

        int ans = -1;
        for (int node = 0; node < n; ++node) {
            int res = f(node, k, 0, t, adj);
            if (res != -1) ans = max(ans, res);
        }
        return ans;
    }
};
