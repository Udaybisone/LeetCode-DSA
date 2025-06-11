class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = -n;

        for (int a = 0; a <= 4; a++) {
            for (int b = 0; b <= 4; b++) {
                if (a == b) continue;

                vector<int> pre(n + 1), parity(n + 1);
                for (int i = 0; i < n; i++) {
                    pre[i + 1] = pre[i] + (s[i] - '0' == a ? 1 : 0) + (s[i] - '0' == b ? -1 : 0);
                    parity[i + 1] = parity[i] ^ (s[i] - '0' == a ? 1 : 0) ^ (s[i] - '0' == b ? 2 : 0);
                }

                vector<vector<int>> pres(4, vector<int>(n + 1, 1e7));
                for (int i = 0; i <= n; i++) pres[parity[i]][i] = pre[i];
                for (int i = 1; i <= n; i++) {
                    for (int j = 0; j < 4; j++) {
                        pres[j][i] = min(pres[j][i], pres[j][i - 1]);
                    }
                }

                vector<int> prev(5, -1);
                for (int e = 0; e < n; e++) {
                    prev[s[e] - '0'] = e;
                    int high = min({prev[a], prev[b], e - k + 1});
                    if (high < 0) continue;
                    ans = max(ans, pre[e + 1] - pres[parity[e + 1] ^ 1][high]);
                }
            }
        }

        return ans;
    }
};