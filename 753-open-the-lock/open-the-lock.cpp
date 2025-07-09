class Solution {
public:
    int openLock(vector<string>& v, string tar) {
        queue<tuple<int, string>> pq;
        unordered_set<string> vis;
        unordered_set<string> st(v.begin(), v.end());

        string start = "0000";
        if (st.count(start)) return -1;

        pq.push({0, start});
        vis.insert(start);

        while (!pq.empty()) {
            auto [dist, code] = pq.front();
            pq.pop();

            if (code == tar) return dist;

            for (int i = 0; i < 4; i++) {
                string up = code, down = code;

                up[i] = (up[i] - '0' + 1) % 10 + '0';
                down[i] = (down[i] - '0' + 9) % 10 + '0';

                for (auto next : {up, down}) {
                    if (!vis.count(next) && !st.count(next)) {
                        pq.push({dist + 1, next});
                        vis.insert(next);
                    }
                }
            }
        }

        return -1;
    }
};
