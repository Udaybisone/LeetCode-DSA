class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int r = 0;
        int ans = 0, sum = 0;
        for(int l=0; l<n; l++){
            while(r<n && !st.count(nums[r])){
                st.insert(nums[r]);
                sum += nums[r];
                r++;
            }
            ans = max(ans,sum);
            st.erase(nums[l]);
            sum -= nums[l];
        }
        return ans;
    }
};