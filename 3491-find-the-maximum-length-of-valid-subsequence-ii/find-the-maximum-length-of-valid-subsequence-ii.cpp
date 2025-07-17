class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k, vector<int>(k, 0));

        for (auto &num : nums) num %= k;

        int ans = 0;

        for (int i = 0; i < k; i++) {
            for (auto num : nums) {
                int complement = (k + i - num) % k;
                dp[i][num] = max(dp[i][num], dp[i][complement] + 1);
                ans = max(ans, dp[i][num]);
            }
        }

        return ans;
    }
};
