class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,1);
        for(int b=0; b<32; b++){
            int idx = -1;
            for(int i=n-1; i>=0; i--){
                if((nums[i]&(1<<b))) idx = i;
                if(idx!=-1) res[i] = max(res[i],idx-i+1);
            }
        }
        return res;
    }
};