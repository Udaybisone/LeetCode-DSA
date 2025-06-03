class Solution {
    set<pair<int,int>> vis;
    map<int, vector<pair<int,int>>> rowMap, colMap;
    map<pair<int,int>, set<pair<int,int>>> adj;

    void dfs(pair<int,int> node) {
        vis.insert(node);
        for(auto& child : adj[node]) {
            if(vis.find(child) == vis.end()) {
                dfs(child);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        // Build maps of rows and columns
        for(auto& stone : stones) {
            int x = stone[0], y = stone[1];
            rowMap[x].emplace_back(x, y);
            colMap[y].emplace_back(x, y);
        }

        // Build the adjacency list
        for(auto& [x, vec] : rowMap) {
            for(size_t i = 1; i < vec.size(); ++i) {
                adj[vec[0]].insert(vec[i]);
                adj[vec[i]].insert(vec[0]);
            }
        }
        for(auto& [y, vec] : colMap) {
            for(size_t i = 1; i < vec.size(); ++i) {
                adj[vec[0]].insert(vec[i]);
                adj[vec[i]].insert(vec[0]);
            }
        }

        // DFS to count components
        int components = 0;
        for(auto& stone : stones) {
            pair<int,int> p = {stone[0], stone[1]};
            if(vis.find(p) == vis.end()) {
                dfs(p);
                components++;
            }
        }

        return stones.size() - components;
    }
};
