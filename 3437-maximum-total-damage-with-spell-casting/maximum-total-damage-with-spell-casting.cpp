class Solution {
    vector<long long>dp;
    long long f(int i,vector<pair<long long,long long>>&v,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int next = n;
        if(i+1<n && v[i+1].first-2 > v[i].first) next = i+1;
        if(next==n && i+2<n && v[i+2].first-2 > v[i].first) next = i+2;
        if(next==n && i+3<n && v[i+3].first-2 > v[i].first) next = i+3;

        long long take = v[i].second + f(next,v,n);
        long long nottake = f(i+1,v,n);

        return dp[i] = max(take,nottake); 
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        vector<pair<long long,long long>>v;
        sort(power.begin(),power.end());
        long long sum = power[0];

        for(int i=1; i<n; i++){
            if(power[i]==power[i-1]) sum += power[i];
            else {
                v.push_back({power[i-1],sum});
                sum = power[i];
            }
        }
        v.push_back({power[n-1],sum});
        n = v.size();

        dp.resize(n,-1);
        long long ans =  f(0,v,n);
        return ans;
    }
};