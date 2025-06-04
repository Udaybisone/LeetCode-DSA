class Solution {
    int n;
    vector<int>dp;
    int f(int sum,int bitmask){
        if(dp[bitmask]!=-1) return dp[bitmask];

        for(int i=1; i<=n; i++){
           if(!(bitmask&(1<<i))){
                if(sum<=i) return dp[bitmask] = true;
                if(!f(sum-i,bitmask | (1<<i))) return dp[bitmask] = true;
           }
        }

        return dp[bitmask] = false;
    }
public:
    bool canIWin(int n, int sum) {
        this->n = n;
        int maxpossible = (n*(n+1))/2;
        if(maxpossible < sum) return false;
        if(sum<=0) return true;
        int bitmask = 0;
        dp.resize(1<<(n+1),-1);
        return f(sum,bitmask);
    }
};