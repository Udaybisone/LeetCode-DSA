class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int sum = 0;
        int ans = 1e9;
        for(int l=0; l<n; l++){
            while(r<n && sum<target) sum += nums[r++];
            if(sum>=target) {
                ans = min(ans,r-l);
            }else break;
            sum -= nums[l];
        }
        return (ans==1e9)?0:ans;
    }
};