class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int>v(n+1,0);
        for(auto p:q){
            v[p[0]]++;
            v[p[1]+1]--;
        }
        for(int i=1; i<n; i++){
            v[i] += v[i-1];
        }
        for(int i=0; i<n; i++){
            if(v[i]<nums[i]) return false;
        }
        return true;
    }
};