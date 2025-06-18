class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>ans(n/3);;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            ans[i/3].push_back(nums[i]);
            if((i+1)%3==0 && (nums[i]-nums[i-2])>k){
                return {};
            }
        }
        return ans;
    }
};