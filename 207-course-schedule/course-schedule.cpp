class Solution {
    vector<vector<int>>adj;
    vector<int>vis,pathvis;
    vector<int>safenode;
    bool dfs(int node){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto nb:adj[node]){
            if(vis[nb] && pathvis[nb]) return true;
            else if(!vis[nb]){
                if(dfs(nb)) return true;
            }
        }
        safenode.push_back(node);
        pathvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        adj.resize(n);
        vis.resize(n,0);
        pathvis.resize(n,0);

        for(auto e:v){
            adj[e[0]].push_back(e[1]);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i)) return false;
            }
        }
        return true;
    }
};