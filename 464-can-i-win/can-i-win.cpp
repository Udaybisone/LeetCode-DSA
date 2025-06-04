class Solution {
    int maxChoosableInteger;
    int desiredTotal;
    unordered_map<int, bool> memo;

    bool canWin(int usedNumbers, int currentTotal) {
        if (memo.count(usedNumbers)) return memo[usedNumbers];

        for (int i = 0; i < maxChoosableInteger; ++i) {
            if (!(usedNumbers & (1 << i))) {
                // i+1 is the number we want to pick
                if (currentTotal + (i + 1) >= desiredTotal) {
                    return memo[usedNumbers] = true;
                }
                if (!canWin(usedNumbers | (1 << i), currentTotal + (i + 1))) {
                    return memo[usedNumbers] = true;
                }
            }
        }

        return memo[usedNumbers] = false;
    }

public:
    bool canIWin(int n, int sum) {
        maxChoosableInteger = n;
        desiredTotal = sum;

        // Early pruning
        int maxPossible = (n * (n + 1)) / 2;
        if (maxPossible < sum) return false;
        if (sum <= 0) return true;

        return canWin(0, 0);
    }
};
