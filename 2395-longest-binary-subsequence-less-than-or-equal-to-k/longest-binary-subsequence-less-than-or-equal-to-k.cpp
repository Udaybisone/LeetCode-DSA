class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int power = 0;
        int value = 0;

        for(int i=n-1; i>=0; i--){
            if(s[i]=='0') power++;
            else if(power<=32 && (value + (1LL<<power))<=k){
                value += (1LL<<power);
                power++;
            }
        }
        return power;
    }
};