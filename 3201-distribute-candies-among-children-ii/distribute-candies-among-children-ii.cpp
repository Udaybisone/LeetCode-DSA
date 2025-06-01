class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long sum = 0;
        for(int i=0; i<=min(n,limit); i++){
            long long rem = n-i;
            long long ways = rem+1;
            if(limit<rem){
                ways -= (2*(rem-limit));
                if(rem%2==0 && limit<(rem/2)) ways += 1;
            }
            sum += max(ways,0LL);
        }
        return sum;
    }
};