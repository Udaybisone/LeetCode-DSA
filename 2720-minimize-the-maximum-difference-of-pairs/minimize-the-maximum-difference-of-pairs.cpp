class Solution {

    bool ispos(int diff,vector<int>&nums,int p){
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1] <= diff){
                p--;
                i++;
            }
        }
        return (p<=0);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0, high = INT_MIN;
        for(int i=1; i<n; i++){
            high = max(high,nums[i]-nums[i-1]);
        }
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(ispos(mid,nums,p)){
                high = mid-1;
                ans = min(ans,mid);
            }else low = mid+1;
        }
        return max(ans,0);
    }
};