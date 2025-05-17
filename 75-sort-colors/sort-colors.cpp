class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n && nums[i]==0) i++;
        for(int j=i+1; j<n; j++){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        while(i<n && nums[i]==1) i++;
        for(int j=i+1; j<n; j++){
           if(nums[j]==1){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};