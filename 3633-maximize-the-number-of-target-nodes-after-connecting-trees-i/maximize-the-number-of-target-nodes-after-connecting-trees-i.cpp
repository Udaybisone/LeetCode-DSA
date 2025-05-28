class Solution {
    int f(int node,int k,vector<int>&vis,vector<vector<int>>&adj){
        vis[node] = 1;
        if(k<0) return 0;
        if(k==0) return 1;
        int sum = 0;
        for(auto it:adj[node]){
            if(!vis[it]){
                sum += (f(it,k-1,vis,adj));
            }
        }
        return sum+1;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = INT_MIN;
        int m = INT_MIN;
        for(auto it:edges1) n = max(n,max(it[0],it[1]));
        for(auto it:edges2) m = max(m,max(it[0],it[1]));
        n++,m++;

        vector<vector<int>>adj1(n);
        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        } 
        vector<vector<int>>adj2(m);
        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        } 
        
        vector<int>vis(n,0);
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i] = f(i,k,vis,adj1);
            fill(vis.begin(),vis.end(),0);
        }

        vector<int>vis2(m,0);
        int mexi = 0;
        for(int i=0; i<m; i++){
            mexi = max(mexi,f(i,k-1,vis2,adj2));
            fill(vis2.begin(),vis2.end(),0);
        }
        for(int i=0;i<n; i++){
            ans[i] += mexi;
        }
        return ans;
    }
};