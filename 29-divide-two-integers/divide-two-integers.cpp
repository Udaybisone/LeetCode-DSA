class Solution {
public:
    long long divide(long long n, long long d) {
        if(n==d) return 1;
        long long sign = 0;
        if(n<0) sign = !sign;
        if(d<0) sign = !sign;
        n = abs(n);
        d = abs(d);
        long long ans = 0;
        if(d>n) return 0;
        while(n>=d){
            long long cnt = 0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            n -= (d<<cnt);
            ans += (1<<cnt);
        }
        if(ans == (1<<31)){
            if(sign) return INT_MIN;
            else return INT_MAX;
        }

        if(sign) ans *= -1;
        return ans;
    }
};