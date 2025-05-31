class Solution {
    vector<vector<vector<int>>>dp;
    int f(int i,int lastidx,int lastsign,vector<int>&nums){
        if(i<0) return 0;
        int take = 0,nottake = 0;
        if(lastidx!=-1 && lastsign!=-1 && dp[i][lastidx][lastsign]!=-1) return dp[i][lastidx][lastsign];
        if(lastsign==-1){
            if(lastidx==-1) take = 1 + f(i-1,i,lastsign,nums);
            else if(nums[lastidx]>nums[i]) take = 1 + f(i-1,i,1,nums);
            else if(nums[lastidx]<nums[i]) take = 1 + f(i-1,i,0,nums);
        }
        
        else if(lastsign==0){
            if(nums[lastidx]>nums[i]) take = 1 + f(i-1,i,1,nums);
        }else{
            if(nums[lastidx]<nums[i]) take = 1 + f(i-1,i,0,nums);
        }
        nottake = f(i-1,lastidx,lastsign,nums);
        if(lastidx!=-1 && lastsign!=-1) dp[i][lastidx][lastsign] = max(take,nottake);
        return max(take,nottake);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // if(n<=2) return n;
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return f(n-1,-1,-1,nums);
    }
};