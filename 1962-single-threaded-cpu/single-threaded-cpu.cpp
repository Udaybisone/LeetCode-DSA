#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define deb3(x, y, z)                                                          \
    cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z   \
         << endl;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<tuple<int, int, int>> vt;

        for (int i = 0; i < n; i++) {
            vt.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(vt.begin(), vt.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        long long curr = 1; // your requested start time
        int i = 0;
        vector<int> res;

        while (i < n || !pq.empty()) {
            // Add all available tasks to PQ
            while (i < n && get<0>(vt[i]) <= curr) {
                int enqueueTime = get<0>(vt[i]);
                int duration = get<1>(vt[i]);
                int index = get<2>(vt[i]);
                pq.push({duration, index});
                i++;
            }

            if (!pq.empty()) {
                auto [dur, idx] = pq.top(); pq.pop();
                res.push_back(idx);
                curr += dur;
            } else {
                // No task available, fast forward time
                if (i < n) {
                    curr = get<0>(vt[i]);
                }
            }
        }

        return res;
    }
};
