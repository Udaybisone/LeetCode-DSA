class Solution {
    vector<int> help(vector<int>&nums,int &k,unordered_map<int,vector<int>>mp,vector<int>vis){
        int n = nums.size();
        for(int i=0;i<n; i++){
            if(vis[i]!=-1) continue;
            int key = nums[i] + 2*k;
            if(mp.count(key) && mp[key].size()>0){
                int idx = mp[key].back();
                mp[key].pop_back();
                vis[idx] = i;
                vis[i] = idx;
            }else return {};
        }
        
        return vis;
    }
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>k;

        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1] or (nums[i]-nums[0])%2) continue;
            k.push_back((nums[i]-nums[0])/2);
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>vis(n,-1);
        for(auto &k:k){
            vector<int> v = help(nums,k,mp,vis);
            if(v.size()){
                vector<int>ans;
                for(int i=0; i<n; i++){
                    if(v[i]>i) ans.push_back(nums[i]+k);
                }
                return ans;
            }
        }
        return {};
    }
};