class Solution {
    unordered_map<string, multiset<string>> adj;
    vector<string> res;

    void f(string node) {
        while (!adj[node].empty()) {
            auto it = adj[node].begin();
            string next = *it;
            adj[node].erase(it);
            f(next);
        }
        res.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        f("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
