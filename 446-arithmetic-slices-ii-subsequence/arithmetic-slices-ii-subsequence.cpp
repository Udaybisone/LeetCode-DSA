class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - (long long)nums[j];
                int count = dp[j][diff];
                dp[i][diff] += count + 1;
                ans += count;  // Only count sequences of length >= 3
            }
        }
        return ans;
    }
};
