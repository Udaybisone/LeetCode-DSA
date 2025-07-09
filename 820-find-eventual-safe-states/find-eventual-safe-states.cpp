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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        adj.resize(n);
        vis.resize(n,0);
        pathvis.resize(n,0);

        for(int i=0; i<n; i++){
            for(auto nb: graph[i]){
                adj[i].push_back(nb);
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};