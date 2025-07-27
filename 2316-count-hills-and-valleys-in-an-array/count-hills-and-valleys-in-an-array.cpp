class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int lastidx = 0;
        for(int i=1; i<n-1;i++){
            if(nums[lastidx]<nums[i] && nums[i+1]<nums[i]) res++;
            else if(nums[lastidx]>nums[i] && nums[i+1]>nums[i]) res++;
            if(nums[i]!=nums[i+1]) lastidx = i;
        }
        return res;
    }
};