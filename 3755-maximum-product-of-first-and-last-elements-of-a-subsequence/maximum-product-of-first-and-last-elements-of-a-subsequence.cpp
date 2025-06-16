class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long n = nums.size();
        vector<long long>maxi(n),mini(n);
        maxi[n-1] = nums[n-1];
        mini[n-1] = nums[n-1];
        for(long long i=n-2; i>=0; i--){
            maxi[i] = max((long long)nums[i],maxi[i+1]);
            mini[i] = min((long long)nums[i],mini[i+1]);
        }

        m--;
        long long ans = LLONG_MIN;
        for(long long i=0; i<(n-m); i++){
            ans = max({ans,((long long)nums[i]*mini[i+m]),((long long)nums[i]*maxi[i+m])});
        }
        return ans;
    }
};