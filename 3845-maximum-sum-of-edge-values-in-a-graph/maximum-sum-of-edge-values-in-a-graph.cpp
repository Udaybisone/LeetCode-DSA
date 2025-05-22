class Solution {
    
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans = 0;
        for(long long i=n; i>2; i-=2) ans += (i*(i-2));
        if(n>1) ans += ((n*1LL*(n-1))*1LL);
        for(long long i=n-1; i>2; i-=2) ans += (i*(i-2));
        vector<int>vis(n,0);
        if(n==edges.size()) ans += 2;
        return ans;
    }
};