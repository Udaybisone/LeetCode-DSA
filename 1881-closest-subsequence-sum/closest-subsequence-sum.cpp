class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> first, second;
        
        for (int i = 0; i < n; i++) {
            if (i < n / 2) first.push_back(nums[i]);
            else second.push_back(nums[i]);
        }

        n = first.size();
        int m = second.size();

        vector<int> fsum, ssum;
        int ans = INT_MAX;

        // Generate all subset sums of first half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) sum += first[i];
            }
            fsum.push_back(sum);
        }

        // Generate all subset sums of second half
        for (int mask = 0; mask < (1 << m); mask++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) sum += second[i];
            }
            ssum.push_back(sum);
        }

        // Sort ssum to enable binary search
        sort(ssum.begin(), ssum.end());

        // For each sum in fsum, find the closest complement in ssum
        for (int sum1 : fsum) {
            int key = goal - sum1;

            auto it = upper_bound(ssum.begin(), ssum.end(), key);

            if (it != ssum.end()) {
                int sum2 = *it;
                ans = min(ans, abs((sum1 + sum2) - goal));
            }

            if (it != ssum.begin()) {
                --it;
                int sum2 = *it;
                ans = min(ans, abs((sum1 + sum2) - goal));
            }
        }

        return ans;
    }
};
