class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>dp = nums;
        priority_queue<pair<int,int>>pq;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            while(!pq.empty() && pq.top().second < (i-k)) pq.pop();

            if(!pq.empty()){
                dp[i] = max(dp[i],dp[i]+pq.top().first);
            }
            pq.push({dp[i],i});
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};