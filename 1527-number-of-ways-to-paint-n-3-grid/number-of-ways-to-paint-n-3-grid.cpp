class Solution {
    int dp[5001][65];
    int mod = 1e9 + 7;
    int f(int r,int c,int crr_st,int prev_st,int n){
        if(r==n) return 1;
        if(c==3){
            return f(r+1,0,0,crr_st,n);
        }
        if(c==0 && dp[r][prev_st]!=-1) return dp[r][prev_st];
        int up_clr = 0;
        if(r>0) up_clr = (prev_st >> (c*2))&3;
        int lf_clr = 0;
        if(c>0) lf_clr = (crr_st & 3);
        int ways = 0;
        for(int clr=1; clr<=3; clr++){
            if(clr != up_clr && clr != lf_clr){
                ways = (ways+f(r,c+1,(crr_st<<2)+clr,prev_st,n))%mod;
            }
        }
        if(c==0) dp[r][prev_st] = ways%mod;
        return ways%mod;
    }
public:
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,0,n)%mod;
    }
};