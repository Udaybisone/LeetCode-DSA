class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++){
            while(i+1<n && nums[i]==nums[i+1]) i++;
            while(!st.empty() && st.top()>nums[i]) {
                res++;
                st.pop();
            }
            if(nums[i]==0) continue;
            if(st.empty() or st.top()!=nums[i]) st.push(nums[i]);
        }
        return res + st.size();
    }
};