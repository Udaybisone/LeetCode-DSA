class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        long long maxreach = 0;
        long long res = 0;
        for(int i=0; i<m; i++){
            if(maxreach>=n) return res;
            while(maxreach<n && nums[i]>maxreach+1){
                maxreach *= 2;
                maxreach++;
                res++;
            }
            maxreach += nums[i];
        }

        while(maxreach < n){
            maxreach *= 2;
            maxreach++;
            res++;
        }
        return res;
    }
};