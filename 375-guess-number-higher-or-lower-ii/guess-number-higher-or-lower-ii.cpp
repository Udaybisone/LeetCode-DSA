class Solution {
    vector<vector<int>>dp;
    int f(int l,int r){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int k = 1e9;
        int mid = (l+r)/2;
        for(int i=mid; i<=r; i++){
            int k1 = f(l,i-1);
            int k2 = f(i+1,r);
            k = min(k,i+max(k2,k1));
        }
        return dp[l][r] = k;
    }
public:
    int getMoneyAmount(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return f(1,n);
    }
};