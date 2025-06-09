class Solution {
    long  f(long  n,long  curr,long  next){
        long  steps = 0;
        while(curr<=n){
            steps += (min(next,n+1)-curr);
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
public:
    long  findKthNumber(long  n, long  k) {
        long  num = 1;
        k--;
        while(k>0){
            long  steps = f(n,num,num+1);
            // cout<<steps<<endl;
            if(steps <= k){
                k -= steps;
                num += 1;
            }else {
                num *= 10;
                k--;
            }
        }
        return  num;
    }
};