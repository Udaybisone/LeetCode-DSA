class Solution {
    long long mod = 1e9 + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({eff[i], speed[i]});
        }

        // Sort by efficiency descending
        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long speedSum = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            int currEff = v[i].first;
            int currSpeed = v[i].second;

            if (pq.size() == k) {
                speedSum -= pq.top();
                pq.pop();
            }

            pq.push(currSpeed);
            speedSum += currSpeed;

            res = max(res, speedSum * currEff);
        }

        return res % mod;
    }
};
