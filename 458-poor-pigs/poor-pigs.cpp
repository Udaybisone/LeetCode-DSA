class Solution {
    int pow(int a,int b){
        int pr = 1;
        while(b>0){
            if(b%2) pr *= a;
            a *= a;
            b = b>>1;
        }
        return pr;
    }
public:
    int poorPigs(int b, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie;
        int pigs = 0;
        while(pow(t+1,pigs) < b) pigs++;
        return pigs;
    }
};