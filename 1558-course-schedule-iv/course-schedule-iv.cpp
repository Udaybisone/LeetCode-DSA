class Solution {
    vector<vector<int>>adj;
    vector<int>vis;
    bool dfs(int node,int &req){
        vis[node] = 1;
        for(auto child:adj[node]){
            if(child==req) return true;
            if(!vis[child]){
                if(dfs(child,req)) return true;
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& v, vector<vector<int>>& q) {
        adj.resize(n);
        vis.resize(n);

        for(auto e:v){
            adj[e[0]].push_back(e[1]);
        }
        vector<bool>ans;
        for(auto &q:q){
            for(int i=0; i<n; i++) vis[i] = 0;
            if(dfs(q[0],q[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};