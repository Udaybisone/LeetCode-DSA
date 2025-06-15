class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<pair<int, int>>> graph(n); // {neighbor, color}, 0 = red, 1 = blue

        // Build graph with color info
        for (auto& e : red)
            graph[e[0]].push_back({e[1], 0});
        for (auto& e : blue)
            graph[e[0]].push_back({e[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, -1)); // [red_dist, blue_dist]
        queue<tuple<int, int, int>> q; // {node, steps, prevColor}

        q.push({0, 0, -1});
        dist[0][0] = dist[0][1] = 0;

        while (!q.empty()) {
            auto [node, steps, prevColor] = q.front(); q.pop();

            for (auto& [next, color] : graph[node]) {
                if (color != prevColor && dist[next][color] == -1) {
                    dist[next][color] = steps + 1;
                    q.push({next, steps + 1, color});
                }
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if (dist[i][0] == -1 && dist[i][1] == -1) res[i] = -1;
            else if (dist[i][0] == -1) res[i] = dist[i][1];
            else if (dist[i][1] == -1) res[i] = dist[i][0];
            else res[i] = min(dist[i][0], dist[i][1]);
        }
        return res;
    }
};
