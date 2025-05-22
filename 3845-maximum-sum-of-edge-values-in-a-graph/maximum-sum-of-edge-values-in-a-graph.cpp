class Solution {
    bool iscycle(int node,int par,vector<vector<int>>&adj,vector<int>&vis){
        vis[node] = 1;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(iscycle(child,node,adj,vis)) return true;
            }else if(child != par) return true;
        }
        return false;
    }   
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
        if(iscycle(0,-1,adj,vis)) ans += 2;
        return ans;
    }
};