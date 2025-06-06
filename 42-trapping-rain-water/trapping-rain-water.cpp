class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        vector<int>v(n,0);
        v[0] = ht[0];
        for(int i=1; i<n-1; i++){
            v[i] = max(ht[i],v[i-1]);
        }
        v[n-1] = ht[n-1];
        for(int i=n-2; i>0; i--){
            int k = max(v[i+1],ht[i]);
            v[i] = min(v[i],k);
        }
        int sum = 0;
        for(int i=1; i<n-1;i++){
            sum += max(0,v[i]-ht[i]);
        }
        return sum;
    }
};