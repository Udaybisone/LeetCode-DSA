class Solution {
public:
    map<char,int>mp;
    int maxDifference(string s) {
        int mxodd = 0, minev = INT_MAX;
        for(auto c:s){
            mp[c]++;
        }
        for(auto it:mp){
            if(it.second%2) mxodd = max(mxodd,it.second);
            else minev = min(minev,it.second);
        }
        return mxodd-minev;
    }
};