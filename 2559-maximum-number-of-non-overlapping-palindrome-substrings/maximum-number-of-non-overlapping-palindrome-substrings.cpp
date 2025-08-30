#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        // minEnd[i] = smallest j >= i such that s[i..j] is palindrome and length >= k
        const int INF = 1e9;
        vector<int> minEnd(n, INF);

        // expand around centers to collect palindromes
        for (int center = 0; center < n; ++center) {
            // odd-length palindromes
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) minEnd[l] = min(minEnd[l], r);
                --l; ++r;
            }
            // even-length palindromes
            l = center; r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) minEnd[l] = min(minEnd[l], r);
                --l; ++r;
            }
        }

        // dp[i] = max palindromes in suffix starting at i
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1]; // skip position i
            if (minEnd[i] != INF) {
                dp[i] = max(dp[i], 1 + dp[minEnd[i] + 1]);
            }
        }
        return dp[0];
    }
};
