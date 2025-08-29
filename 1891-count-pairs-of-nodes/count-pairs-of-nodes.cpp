class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& q) {
        vector<int> d(n, 0);
        vector<vector<int>> adj(n);
        unordered_map<long long, int> edgeCount;

        for (auto& it : edges) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            d[u]++;
            d[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);

            if (u > v) swap(u, v); // ensure (u,v) order
            edgeCount[1LL * u * n + v]++; // encode pair uniquely
        }

        vector<pair<int, int>> dg;
        for (int i = 0; i < n; i++) {
            dg.push_back({d[i], i});
        }

        sort(dg.begin(), dg.end());

        vector<int> degOnly;
        for (auto& p : dg) degOnly.push_back(p.first);

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[dg[i].second] = i;
        }

        vector<int> ans;

        for (int query : q) {
            int total = 0;
            int i = 0, j = n - 1;
            // Two-pointer approach to count pairs (i < j) where deg[i] + deg[j] > query
            while (i < j) {
                if (degOnly[i] + degOnly[j] > query) {
                    total += (j - i);
                    j--;
                } else {
                    i++;
                }
            }

            // Subtract overcounted pairs due to common edges
            for (auto& it : edgeCount) {
                int key = it.first;
                int u = key / n;
                int v = key % n;
                int common = it.second;
                if (d[u] + d[v] > query && d[u] + d[v] - common <= query) {
                    total--;
                }
            }

            ans.push_back(total);
        }

        return ans;
    }
};
