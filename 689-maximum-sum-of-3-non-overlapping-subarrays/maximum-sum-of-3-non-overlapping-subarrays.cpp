class Solution {
    vector<int>nums,pre,res;
    int n;
    vector<vector<int>>dp;
    int f2(int i,int cnt,int &k){
        if(cnt==0) return 0;
        if((i+k)>n) return INT_MIN;
        if(dp[i][cnt]!=-1) return dp[i][cnt];

        int take = (pre[i+k-1] - ((i==0)?0:pre[i-1]) + f2(i+k,cnt-1,k));
        int nottake = f2(i+1,cnt,k);

        return dp[i][cnt] = max(take,nottake);
    }

    void f(int i,int cnt,int &k){
        if(cnt==0) return;
        if(i>=n) return;

        int take = pre[i+k-1] - ((i==0)?0:pre[i-1]) + f2(i+k,cnt-1,k);
        int nottake  = f2(i+1,cnt,k);

        if(take>=nottake){
            res.push_back(i);
            f(i+k,cnt-1,k);
        }else f(i+1,cnt,k);

    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        this->nums = nums;
        n = nums.size();
        pre = nums;
        dp.resize(n+1,vector<int>(4,-1));

        for(int i=1; i<n; i++) pre[i] += pre[i-1];

        f(0,3,k);

        return res;
    }
};