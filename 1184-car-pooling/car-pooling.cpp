class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) return a[1] < b[1];
        return a[2] < b[2];
    }
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        sort(trips.begin(), trips.end(), cmp);

        for (const auto& t : trips) {
            int pass = t[0], st = t[1], end = t[2];

            while (!pq.empty() && pq.top().first <= st) {
                sum -= pq.top().second;
                pq.pop();
            }

            sum += pass;
            if (sum > cap) return false;

            pq.push({end, pass});
        }

        return true;
    }
};
