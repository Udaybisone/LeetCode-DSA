class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>pre(n,0);
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1];
            if(nums[i]==nums[i-1]) pre[i]++;
        }

        int mini = n;
        for(int i=0;i<n; i++){
            if(i>=mini) break;
            int key = nums[i] + (n-1);
            int idx = upper_bound(nums.begin(),nums.end(),key)-nums.begin();
            int change = i + (n-idx) + (pre[idx-1] - pre[i]);
            mini = min(mini,change);
        }
        return mini;;
    }
};