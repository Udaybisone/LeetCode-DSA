class Solution {
    vector<int>color;

    bool dfs(int node, int par,vector<vector<int>>&adj){
        for(auto nb:adj[node]){
            if(nb==par) continue;
            if(color[nb]==-1){
                color[nb] = (1-color[node]);
                if(!dfs(nb,node,adj)) return false;
            }else if(color[nb]==color[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        color.resize(n,-1);

        for(int i=0;i<n; i++){
            if(color[i]==-1){
                color[i] = 0;
                if(!dfs(i,-1,adj)) return false;
            }
        }
        return true;
    }
};