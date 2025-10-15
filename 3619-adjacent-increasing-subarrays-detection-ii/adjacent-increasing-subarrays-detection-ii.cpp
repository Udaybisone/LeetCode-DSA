class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        int c = 1;
        int prelen = 0; 
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]) c++;
            else{
                ans = max({ans,min(prelen,c),c/2});
                prelen = c;
                c = 1;
            }
        }
        ans = max({ans,min(prelen,c),c/2});
        return ans;
    }
};