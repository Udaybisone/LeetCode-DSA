class Solution {
    int n;
    unordered_map<int, bool> dp;

    bool f(int sum, int bitmask) {
        if (dp.count(bitmask)) return dp[bitmask];

        for (int i = 1; i <= n; i++) {
            if (!((1 << i) & bitmask)) {
                if (i >= sum) {
                    return dp[bitmask] = true;  // current player wins immediately
                }
                if (!f(sum - i, bitmask | (1 << i))) {
                    return dp[bitmask] = true;  // current player can force a win
                }
            }
        }
        return dp[bitmask] = false;  // no winning move found
    }

public:
    bool canIWin(int n, int sum) {
        this->n = n;

        int maxPossible = (n * (n + 1)) / 2;
        if (sum <= 0) return true;
        if (maxPossible < sum) return false;

        return f(sum, 0);  // initial state: sum needed, no numbers used
    }
};
