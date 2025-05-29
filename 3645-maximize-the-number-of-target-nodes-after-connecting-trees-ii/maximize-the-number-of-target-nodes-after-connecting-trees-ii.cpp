class Solution {
    void bfs(vector<vector<int>>& adj, vector<int>& nnil, vector<int>& level) {
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        level[0] = 0;

        nnil.assign(n, 0);
        nnil[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    level[neighbor] = level[node] + 1;
                    q.push(neighbor);
                    if (level[neighbor] >= nnil.size()) nnil.resize(level[neighbor] + 1, 0);
                    nnil[level[neighbor]]++;
                }
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = 0, m = 0;
        for (auto& edge : edges1) n = max(n, max(edge[0], edge[1]));
        for (auto& edge : edges2) m = max(m, max(edge[0], edge[1]));
        n++, m++;

        vector<vector<int>> adj1(n), adj2(m);
        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        // BFS on first graph
        vector<int> nnil, level(n, -1);
        bfs(adj1, nnil, level);

        // Precompute cumulative sums for even/odd levels
        vector<int> prefixEven(nnil.size(), 0), prefixOdd(nnil.size(), 0);
        for (int i = 0; i < nnil.size(); ++i) {
            prefixEven[i] = (i > 0 ? prefixEven[i - 1] : 0) + (i % 2 == 0 ? nnil[i] : 0);
            prefixOdd[i] = (i > 0 ? prefixOdd[i - 1] : 0) + (i % 2 == 1 ? nnil[i] : 0);
        }

        // Compute even contributions for the first graph
        vector<int> even(n, 0);
        for (int i = 0; i < n; ++i) {
            int lvl = level[i];
            even[i] = (lvl % 2 == 0 ? prefixEven.back() : prefixOdd.back());
        }

        // BFS on second graph
        nnil.clear();
        level.assign(m, -1);
        bfs(adj2, nnil, level);

        // Precompute cumulative sums for second graph
        prefixEven.assign(nnil.size(), 0);
        prefixOdd.assign(nnil.size(), 0);
        for (int i = 0; i < nnil.size(); ++i) {
            prefixEven[i] = (i > 0 ? prefixEven[i - 1] : 0) + (i % 2 == 0 ? nnil[i] : 0);
            prefixOdd[i] = (i > 0 ? prefixOdd[i - 1] : 0) + (i % 2 == 1 ? nnil[i] : 0);
        }

        // Compute max odd contribution from the second graph
        int maxOdd = 0;
        for (int i = 0; i < m; ++i) {
            int lvl = level[i];
            maxOdd = max(maxOdd, (lvl % 2 == 1 ? prefixOdd.back() : prefixEven.back()));
        }

        // Add max odd contribution to all even values
        for (int i = 0; i < n; ++i) {
            even[i] += maxOdd;
        }

        return even;
    }
};
