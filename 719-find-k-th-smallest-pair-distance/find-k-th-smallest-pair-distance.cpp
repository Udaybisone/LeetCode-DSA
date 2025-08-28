class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int l = 0, r = nums[n-1] - nums[0];

        while(l<=r){
            int mid = l + (r-l)/2;
            int total = 0;
            for(int i=0; i<n; i++){
                int key = nums[i] + mid;
                int idx = upper_bound(nums.begin(),nums.end(),key)- nums.begin();
                total += (idx-i-1);
            }
            
            if(total < k) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
};