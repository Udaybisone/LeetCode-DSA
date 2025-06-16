class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        vector<pair<int,int>>freq(n);
        for(int i=0; i<n; i++){
            
            freq[i].first = mp[nums[i]*2];
            mp[nums[i]]++;
        }
        mp.clear();
        for(int i=n-1; i>=0; i--){
            freq[i].second = mp[nums[i]*2];
            mp[nums[i]]++;
        }
        long long ans = 0;
        long long mod = 1e9+7;
        for(int i=1; i<n-1; i++){
            long long lf = freq[i].first;
            long long rt = freq[i].second;
            ans = (ans + (lf*rt)%mod)%mod;
        }
        return ans;
    }
};