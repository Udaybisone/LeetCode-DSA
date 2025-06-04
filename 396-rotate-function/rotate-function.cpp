class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        for(int i=0; i<n;i++) ans += (i*nums[i]);
        int lastval = ans;
        for(int i=n-1; i>0; i--){
            int val = lastval - (n-1)*nums[i] + (sum-nums[i]);
            ans = max(ans,val);
            lastval = val;
        }
        return ans;
    }
};