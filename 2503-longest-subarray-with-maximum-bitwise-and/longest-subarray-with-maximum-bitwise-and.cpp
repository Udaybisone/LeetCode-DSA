class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int cnt = 0, maxCnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxVal) {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            } else {
                cnt = 0;
            }
        }
        return maxCnt;
    }
};
