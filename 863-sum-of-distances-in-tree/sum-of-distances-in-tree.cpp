class Solution {
    vector<vector<int>> adj;
    vector<int> subtreeSize;
    vector<int> distSum;
    int n;

    void dfs1(int node, int parent) {
        subtreeSize[node] = 1;  // include self
        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs1(child, node);
            subtreeSize[node] += subtreeSize[child];
            distSum[node] += distSum[child] + subtreeSize[child];
        }
    }

    void dfs2(int node, int parent) {
        for (int child : adj[node]) {
            if (child == parent) continue;
            // Move root from node to child
            distSum[child] = distSum[node] - subtreeSize[child] + (n - subtreeSize[child]);
            dfs2(child, node);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        subtreeSize.resize(n, 0);
        distSum.resize(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);  // First DFS to compute subtree sizes and initial distance sum
        dfs2(0, -1);  // Second DFS to adjust distances for all other nodes

        return distSum;
    }
};
