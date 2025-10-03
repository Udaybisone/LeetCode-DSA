class Solution {
    vector<int> topoSort(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);

            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return order;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);

        if (rowOrder.size() != k || colOrder.size() != k) {
            return {}; 
        }

        vector<int> rowPos(k + 1), colPos(k + 1);
        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int num = 1; num <= k; ++num) {
            int r = rowPos[num], c = colPos[num];
            matrix[r][c] = num;
        }

        return matrix;
    }
};
