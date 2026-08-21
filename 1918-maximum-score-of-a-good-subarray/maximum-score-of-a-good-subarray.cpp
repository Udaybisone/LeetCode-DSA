class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k-1,j = k+1;
        int mini = nums[k];
        int ans = 0;
        while(i>=0 && j<n){
            if(mini <= nums[i] && mini<=nums[j]){
                i--;
                j++;
            }else if(mini <= nums[i]) i--;
            else if(mini<=nums[j]) j++;
            else{
                ans = max(ans,(j-i-1)*mini);
                if(nums[i]>nums[j]){
                    mini = nums[i];
                    i--;
                }else{
                    mini = nums[j];
                    j++;
                }
            }
        }

        while(i>=0){
            if(mini<=nums[i]) i--;
            else{
                ans = max(ans,(j-i-1)*mini);
                mini = nums[i];
                i--;
            }
        }

        while(j<n){
            if(mini<=nums[j]) j++;
            else{
                ans = max(ans,(j-i-1)*mini);
                mini = nums[j];
                j++;
            }
        }

        ans = max(ans,mini*n);
        return ans;
    }
};