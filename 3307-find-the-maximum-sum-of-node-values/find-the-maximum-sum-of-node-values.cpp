class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        // base sum of all original values
        long long base = 0;
        for (int v : nums) base += v;

        // compute all deltas = (nums[i] XOR k) - nums[i]
        vector<long long> delta(n);
        for (int i = 0; i < n; i++) {
            delta[i] = (long long)(nums[i] ^ k) - nums[i];
        }

        // collect positives
        long long sumPos = 0;
        int countPos = 0;
        long long minPos = LLONG_MAX;
        long long maxNeg = LLONG_MIN;  // will track the best (i.e. largest) non-positive delta

        for (long long d : delta) {
            if (d > 0) {
                sumPos += d;
                countPos++;
                minPos = min(minPos, d);
            } else {
                maxNeg = max(maxNeg, d);
            }
        }

        long long bestDelta;
        if ((countPos & 1) == 0) {
            // even, we can take them all
            bestDelta = sumPos;
        } else {
            // odd, we must drop one positive or add one non-positive
            // but maybe there are no non-positives? then maxNeg stays very negative,
            // so dropping a positive is automatically better.
            long long option1 = sumPos - minPos;    // drop the smallest positive
            long long option2 = sumPos + maxNeg;    // add the best negative (≤0)
            bestDelta = max(option1, option2);
        }

        return base + bestDelta;
    }
};
