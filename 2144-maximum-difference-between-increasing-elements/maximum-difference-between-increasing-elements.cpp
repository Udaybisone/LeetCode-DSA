class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int a = nums[0], b = -1;
        int ans = -1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]<=a) a = nums[i];
            else{
                ans = max(ans,nums[i]-a);
            }
        }
        return ans;
    }
};