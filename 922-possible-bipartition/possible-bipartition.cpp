class Solution {
    vector<vector<int>>adj;
    vector<int>color;
    bool f(int node){
        for(auto child:adj[node]){
            if(color[child]==-1){
                color[child] = (color[node]==0)?1:0;
                if(!f(child)) return false;
            }else if(color[node]==color[child]) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj.resize(n+2);
        color.resize(n+2,-1);
        for(auto e:dislikes){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                color[i] = 1;
                if(!f(i)) return false;
            }
        }
        return true;
    }
};