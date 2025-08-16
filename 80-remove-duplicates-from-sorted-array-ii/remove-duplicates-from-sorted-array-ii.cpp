class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        if(i+1<n && nums[i]==nums[i+1]) i++;
        for(int j=i+1; j<n; j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
                if(j+1<n && nums[j]==nums[j+1]){
                    i++;
                    j++;
                    nums[i] = nums[j];
                }
            }
        }
        return i+1;
    }
};