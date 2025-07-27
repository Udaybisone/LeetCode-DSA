class Solution {
    int mod = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int le, int ri) {
        vector<long long>v;
        for(int i=0; i<n; i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                v.push_back(sum);  
            }
        }
        sort(v.begin(),v.end());

        long long sum = 0;
        for(int i=le-1; i<ri; i++) sum = (sum+v[i])%mod;
        return sum;
    }
};