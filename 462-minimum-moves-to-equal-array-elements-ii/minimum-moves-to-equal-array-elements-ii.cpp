class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long ans = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        long long total = accumulate(nums.begin(),nums.end(),0LL);
        long long sum1 = 0;
        for(int i=0; i<n; i++){
            long long sum2 = total - (sum1 + nums[i]);
            long long k = 1LL*(i*1LL*nums[i]) - sum1 + sum2 - 1LL*(n-(i+1))*1LL*nums[i];
            ans = min(ans,k);
            sum1 += nums[i];
        }
        return ans;
    }
};