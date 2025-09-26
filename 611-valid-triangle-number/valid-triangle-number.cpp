class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,i=0;
        sort(nums.begin(),nums.end());
        for(i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i] + nums[j];
                int diff = nums[j] - nums[i];

                int idx1 = upper_bound(nums.begin()+j+1,nums.end(),diff)-nums.begin();
                int idx2 = lower_bound(nums.begin()+j+1,nums.end(),sum)-nums.begin()-1;

                ans += max(0,idx2-idx1+1);
            }
        }
        return ans;
    }
};