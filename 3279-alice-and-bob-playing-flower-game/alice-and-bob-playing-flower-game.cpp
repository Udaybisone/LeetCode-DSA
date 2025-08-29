class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = (n/2)*(ceil(m*1.0/2));
        ans += ((m/2)*(ceil(n*1.0/2)));

        return ans;
    }
};