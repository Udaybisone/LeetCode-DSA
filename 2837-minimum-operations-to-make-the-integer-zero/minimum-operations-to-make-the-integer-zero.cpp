#define setbit(N) __builtin_popcountll(N)

long long pow(long long a, long long b) {
    long long pr = 1;
    while (b > 0) {
        if (b % 2) pr *= a;
        a *= a;
        b /= 2;
    }
    return pr;
}

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int i=0; i<=60; i++){
            long long k = num1 - ((long long)i*num2);
            if(k<0) continue;

            long long freq = i;

            int stbit = setbit(k);
            if(stbit <= i && i <= k) return i;
        }

        return -1;
    }
};