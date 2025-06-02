class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 1e9;
        for(int k=0; k<=n-3; k++){
            int i=k+1;
            int j = n-1;
            while(i<j){
                int sum = nums[i]+nums[j]+nums[k];
                if(ans==1e9 || abs(tar-sum)<abs(tar-ans)) {
                    ans = sum;
                }
                if(sum==tar) return tar;
                else if(sum>tar) j--;
                else i++;
            }
            while((k+1)<n && nums[k+1]==nums[k]) k++;
        }
        return ans;
    }
};