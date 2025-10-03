class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [currDist, node] = pq.top(); pq.pop();

            if (currDist > dist[node]) continue;

            for (auto& [neighbor, weight] : adj[node]) {
                int nextDist = currDist + weight + 1;
                if (nextDist <= maxMoves && nextDist < dist[neighbor]) {
                    dist[neighbor] = nextDist;
                    pq.emplace(nextDist, neighbor);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= maxMoves) ans++;
        }

        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int remU = dist[u] == INT_MAX ? 0 : maxMoves - dist[u];
            int remV = dist[v] == INT_MAX ? 0 : maxMoves - dist[v];
            ans += min(cnt, remU + remV);
        }

        return ans;
    }
};
