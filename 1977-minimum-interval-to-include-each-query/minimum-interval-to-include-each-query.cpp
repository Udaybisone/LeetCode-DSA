class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,vector<int>& queries) {
        int m = queries.size();
        
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return (a[1] - a[0]) < (b[1] - b[0]);
            }
        );

        set<pair<int, int>> s;

        for (int i = 0; i < m; i++) {
            s.insert({queries[i], i});
        }

        vector<int> ans(m, -1);

        for (auto &in : intervals) {
            int l = in[0];
            int r = in[1];
            int len = r - l + 1;

            auto it = s.lower_bound({l, -1});

            while (it != s.end() && it->first <= r) {
                ans[it->second] = len;
                it = s.erase(it);
            }
        }

        return ans;
    }
};