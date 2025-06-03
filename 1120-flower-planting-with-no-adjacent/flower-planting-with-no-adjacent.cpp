class Solution {
    vector<vector<int>>adj;
    vector<int>nodecolor;
    void f(int node){
        for(auto child:adj[node]){
            if(nodecolor[child-1]) continue;
            vector<int>v(5,0);
            for(auto nb:adj[child]){
                if(nodecolor[nb-1]) v[nodecolor[nb-1]] = 1;
            }
            for(int i=1; i<=4; i++){
                if(!v[i]){
                    nodecolor[child-1] = i;
                    f(child);
                    break;
                }
            }
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        adj.resize(n+1);
        nodecolor.resize(n,0);
        for(auto p:paths){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        for(int i=1; i<=n; i++){
            if(!nodecolor[i-1]){
                nodecolor[i-1] = 1;
                f(i);
            }
        }
        return nodecolor;
    }
};