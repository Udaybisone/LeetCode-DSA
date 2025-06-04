class Solution {
    set<vector<int>> ans;
    vector<int> v;

    void f(int i, int sum, vector<int>& nums) {
        int n = nums.size();
        if (sum == 0) {
            ans.insert(v); // Already sorted path since nums is sorted
            return;
        }
        if (i >= n || sum < 0) return;

        for (int j = i; j < n; ++j) {
            // Skip duplicates at the same recursive level
            if (j > i && nums[j] == nums[j - 1]) continue;
            if (nums[j] > sum) break;

            v.push_back(nums[j]);
            f(j + 1, sum - nums[j], nums);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int sum) {
        sort(nums.begin(), nums.end()); // Required for skipping duplicates
        f(0, sum, nums);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
