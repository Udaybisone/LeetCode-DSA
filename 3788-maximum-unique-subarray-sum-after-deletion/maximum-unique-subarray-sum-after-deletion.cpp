class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0;
        set<int>st;
        int k = INT_MIN;
        for(auto &it:nums){
            k = max(k,it);
            if(it>0 && st.find(it)==st.end()){
                ans += it;
                st.insert(it);
            }
        }
        return (ans==0)?k:ans;
    }
};