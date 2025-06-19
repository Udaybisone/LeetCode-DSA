class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int prev = nums[0];
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(nums[i]-prev > k){
                prev = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};