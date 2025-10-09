class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
        int n = v1.size(), m = v2.size();
        vector<vector<int>> ans;

        if (n == 0 || m == 0 || k == 0) return ans;

        using T = tuple<int, int, int>;  // (sum, i, j)
        priority_queue<T, vector<T>, greater<T>> pq;
        set<pair<int, int>> visited;

        pq.push({v1[0] + v2[0], 0, 0});
        visited.insert({0, 0});

        while (!pq.empty() && ans.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({v1[i], v2[j]});

            if (i + 1 < n && !visited.count({i + 1, j})) {
                pq.push({v1[i + 1] + v2[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            if (j + 1 < m && !visited.count({i, j + 1})) {
                pq.push({v1[i] + v2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};
