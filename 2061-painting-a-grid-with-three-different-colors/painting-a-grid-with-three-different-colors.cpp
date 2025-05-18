class Solution {
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int f(int r,int c,int crr_st,int prev_st,int n,int m){
        if(c == m) return 1;
        if(r == n){
            return f(0,c+1,0,crr_st,n,m);
        }
        if(r==0 && dp[c][prev_st]!=-1) return dp[c][prev_st]%mod;
        int up_clr = 0;
        if(r>0) up_clr = crr_st & 3;
        int lf_clr = 0;
        if (c > 0) lf_clr = (prev_st >> (2 * r)) & 3; 

        int ways = 0;
        for(int clr=1; clr<=3; clr++){
            if(clr!=up_clr && clr!=lf_clr){
                ways = (ways + f(r+1,c,(crr_st<<2)+clr,prev_st,n,m))%mod;
            }
        }
        if(r==0) dp[c][prev_st] = ways%mod;
        return ways%mod;
    }
public:
    int colorTheGrid(int n, int m) {
        dp.resize(1002,vector<int>(2028,-1));
        return f(0,0,0,0,n,m)%mod;
    }
};