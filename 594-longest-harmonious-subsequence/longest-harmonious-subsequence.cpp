class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        int ans = 0;
        for(auto num:nums){
            mp[num]++;
            if(mp.count(num-1)) ans = max(ans,mp[num-1]+mp[num]);
            if(mp.count(num+1)) ans = max(ans,mp[num+1]+mp[num]);
        }
        return ans;
    }
};