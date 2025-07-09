class Solution {
    vector<vector<int>>adj;
    set<pair<int,int>>st;
    int ans = 0;
    void dfs(int node, int par){

        for(auto child:adj[node]){
            if(child==par) continue;
            if(st.find({node,child})!=st.end()) ans++;
            dfs(child,node);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& v) {
        adj.resize(n);

        for(auto e:v){
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]); 
            st.insert({e[0],e[1]});
        }

        dfs(0,-1);
        return ans;
    }
};