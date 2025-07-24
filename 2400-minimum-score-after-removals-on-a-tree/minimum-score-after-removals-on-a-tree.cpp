class Solution {
    vector<int> subxor;
    vector<vector<int>> adj;
    vector<unordered_set<int>> v;
    int res = INT_MAX;

    void dfs(int node, int par, vector<int>& nums) {
        subxor[node] = nums[node];
        v[node].insert(node);
        for (auto child : adj[node]) {
            if (child == par) continue;
            dfs(child, node, nums);
            v[node].insert(v[child].begin(), v[child].end());
            subxor[node] ^= subxor[child];
        }
    }

    void dfs3(int node, int par, int& removedNode) {
        for (auto child : adj[node]) {
            if (child == par || child == removedNode) continue;

            if (v[child].find(removedNode) != v[child].end()) {
                // removedNode is in child subtree
                int xor1 = subxor[child] ^ subxor[removedNode];
                int xor2 = subxor[0] ^ subxor[child];
                int xor3 = subxor[removedNode];

                int maxX = max({xor1, xor2, xor3});
                int minX = min({xor1, xor2, xor3});
                res = min(res, maxX - minX);
            } else {
                // removedNode is not in child subtree
                int xor1 = subxor[child];
                int xor2 = subxor[0] ^ subxor[child] ^ subxor[removedNode];
                int xor3 = subxor[removedNode];

                int maxX = max({xor1, xor2, xor3});
                int minX = min({xor1, xor2, xor3});
                res = min(res, maxX - minX);
            }

            dfs3(child, node, removedNode);
        }
    }

    void dfs2(int node, int par) {
        for (auto child : adj[node]) {
            if (child == par) continue;

            // Simulate removing the edge (node-child)
            dfs3(0, -1, child);

            // Fix: need to recurse dfs2 for deeper edges
            dfs2(child, node);
        }
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        subxor.resize(n);
        adj.resize(n);
        v.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums); // Build subxor and subtree info
        dfs2(0, -1);      // Try all first-edge removals

        return res;
    }
};
