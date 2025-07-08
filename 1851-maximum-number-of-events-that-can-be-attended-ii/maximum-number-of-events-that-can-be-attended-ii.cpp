class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];  // sort by start time
    }

    vector<vector<int>> dp;

    int f(int i, int k, vector<vector<int>> &e, int n) {
        if (i >= n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

    
        int end = e[i][1];
        int nextIdx = upper_bound(e.begin() + i, e.end(), end,
                              [](int t, const vector<int>& v) { return t < v[0]; }) - e.begin();

        int take = e[i][2] + f(nextIdx, k - 1, e, n);
        int notTake = f(i + 1, k, e, n);

        return dp[i][k] = max(take, notTake);
    }

public:
    int maxValue(vector<vector<int>>& e, int k) {
        int n = e.size();
        sort(e.begin(), e.end(), comp);
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return f(0, k, e, n);
    }
};
