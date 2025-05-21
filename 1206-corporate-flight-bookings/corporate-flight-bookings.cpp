class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int>v(n+1,0);
        for(auto p:b){
            v[--p[0]] += p[2];
            v[p[1]] -= p[2];
        }
        for(int i=1; i<n; i++){
            v[i] += v[i-1];
        }
        v.pop_back();
        return v;
    }
};