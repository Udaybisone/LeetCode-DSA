class Solution {
    unordered_map<long long,long long>dp;
    long long f(long long n){
        if(n==1) return 0;
        if(dp.count(n)) return dp[n];
        if(n%2==0) return dp[n] = 1 + f(n/2);

        return dp[n] = 1LL + min(f(n+1),f(n-1));
    }
public:
    long long integerReplacement(long long n) {
        return f(n);
    }
};