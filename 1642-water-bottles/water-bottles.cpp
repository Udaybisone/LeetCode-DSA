class Solution {
public:
    int numWaterBottles(int n, int m) {
        
        int empty = 0;
        int full = n;
        int ans = 0;

        while((empty+full)>=m){
            ans += full;
            empty += full;
            full = 0;
            full = (empty/m);
            empty %= m;
        }
        return ans+full;
    }
};