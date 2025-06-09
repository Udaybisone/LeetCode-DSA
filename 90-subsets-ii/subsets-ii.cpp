class Solution {
    set<vector<int>>res;
    vector<int>v;
    int n;
    void f(int i,vector<int>&nums){
        if(i>=n){
            res.insert(v);
            return;
        }
        v.push_back(nums[i]);
        f(i+1,nums);
        v.pop_back();
        f(i+1,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        f(0,nums);
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
    }
};