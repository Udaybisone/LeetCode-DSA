class Solution {
public:
    vector<int> shortestAlternatingPaths(int &n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<int>> adj(n);
        map<pair<int,int>,int> color; // edge → color (1: red, 2: blue, 3: both)

        for (auto& e : red) {
            adj[e[0]].push_back(e[1]);
            color[{e[0], e[1]}] = 1; // red
        }
        for (auto& e : blue) {
            adj[e[0]].push_back(e[1]);
            if (color[{e[0], e[1]}] == 1)
                color[{e[0], e[1]}] = 3; // both red and blue
            else
                color[{e[0], e[1]}] = 2; // blue
        }

        // dist[node][prevColor], where prevColor = 0 (red), 1 (blue)
        vector<vector<int>> dist(n, vector<int>(2, 1e9));
        dist[0][0] = 0; // red
        dist[0][1] = 0; // blue

        // priority queue: {moves, node, prevColor}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0}); // simulate coming from red
        pq.push({0, 0, 1}); // simulate coming from blue

        while (!pq.empty()) {
            auto [moves, node, prevColor] = pq.top();
            pq.pop();

            for (int nb : adj[node]) {
                int clr = color[{node, nb}];

                // Try switching from red to blue
                if ((clr == 2 || clr == 3) && prevColor == 0) {
                    if (dist[nb][1] > moves + 1) {
                        dist[nb][1] = moves + 1;
                        pq.push({moves + 1, nb, 1});
                    }
                }

                // Try switching from blue to red
                if ((clr == 1 || clr == 3) && prevColor == 1) {
                    if (dist[nb][0] > moves + 1) {
                        dist[nb][0] = moves + 1;
                        pq.push({moves + 1, nb, 0});
                    }
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int minDist = min(dist[i][0], dist[i][1]);
            ans[i] = (minDist == 1e9) ? -1 : minDist;
        }
        return ans;
    }
};
