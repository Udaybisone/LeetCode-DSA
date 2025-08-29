#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<long long> v1, v2;
    unordered_map<long long,int> mp1, mp2;
    int n , m;
    const long long mod = 1000000007LL;
    vector<vector<long long>> dp;
    vector<char> isCommon1, isCommon2;

    long long f(int i,int flag){
        if(flag==0 && i>=n) return 0;
        if(flag==1 && i>=m) return 0;
        long long res = 0;

        if(dp[i][flag] != -1) return dp[i][flag];
        if(flag==0){
            long long change = 0;
            // only allow change if this position is an actual common element
            if(isCommon1[i] && mp2.count(v1[i])) change = v1[i] + f(mp2[v1[i]]+1,1);
            long long notchange = v1[i] + f(i+1,flag);
            res = max(change,notchange);
        }else{
            long long change = 0;
            if(isCommon2[i] && mp1.count(v2[i])) change = v2[i] + f(mp1[v2[i]]+1,0);
            long long notchange = v2[i] + f(i+1,flag);
            res = max(change,notchange);
        }

        return dp[i][flag] = res;
    }

public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        long long sum1 = 0;
        long long sum2 = 0;
        int i=0,j=0;

        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                if(sum1 != 0){
                    v1.push_back(sum1);
                    isCommon1.push_back(0);
                }
                if(sum2 != 0){
                    v2.push_back(sum2);
                    isCommon2.push_back(0);
                }
                v1.push_back(nums1[i]);
                isCommon1.push_back(1);
                v2.push_back(nums2[j]);
                isCommon2.push_back(1);
                mp1[v1.back()] = (int)v1.size()-1;
                mp2[v2.back()] = (int)v2.size()-1;
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }else if(nums1[i]<nums2[j]) sum1 += nums1[i++];
            else sum2 += nums2[j++];
        }

        while(i<n) sum1 += nums1[i++];
        while(j<m) sum2 += nums2[j++];

        if(sum1 != 0){
            v1.push_back(sum1);
            isCommon1.push_back(0);
        }
        if(sum2 != 0){
            v2.push_back(sum2);
            isCommon2.push_back(0);
        }

        n = v1.size();
        m = v2.size();

        dp.resize(max(n, m) + 2, vector<long long>(2, -1));
        // ensure isCommon vectors have sizes matching when v1 or v2 might be empty
        if((int)isCommon1.size() < n) isCommon1.resize(n, 0);
        if((int)isCommon2.size() < m) isCommon2.resize(m, 0);

        long long ans1 = 0;
        long long ans2 = 0;
        if(n>0) ans1 = f(0,0);
        if(m>0) ans2 = f(0,1);

        long long ans = max(ans1, ans2) % mod;
        return (int)ans;
    }
};
