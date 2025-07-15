class Solution {
    vector<vector<int>>adj;
    vector<int>vis;
    int cnt;
    void dfs(int node){
        cnt++;
        vis[node] = 1;
        for(auto &nb:adj[node]){
            if(!vis[nb]){
                dfs(nb);
            }
        }
    }
    bool f(int node){
        if(adj[node].size() != (cnt-1)) return false;
        vis[node] = 2;
        for(auto &nb:adj[node]){
            if(vis[nb]!=2){
                if(!f(nb)) return false;
            }
        }
        return true;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n,0);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;

        for(int i=0; i<n; i++){
            if(vis[i]==0){
                cnt = 0;
                dfs(i);
                cout<<cnt<<endl;
                if(f(i)) res++;
            }
        }
        return res;
    }
};