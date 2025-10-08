class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long su) {
        int n = s.size(), m = p.size();
        sort(p.begin(),p.end());

        vector<int>ans(n);

        for(int i=0; i<n; i++){
            long long key = ceil(su*1.0/s[i]);
            int idx = lower_bound(p.begin(),p.end(),key)-p.begin();
            ans[i] = m-idx;
        }
        return ans;
    }
};