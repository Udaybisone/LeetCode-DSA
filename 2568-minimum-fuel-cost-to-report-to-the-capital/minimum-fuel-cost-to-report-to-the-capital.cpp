class Solution {
    vector<vector<int>>adj;
    long long ans = 0;
    long long s;
    long long dfs(int node,int par){
        long long sum = 1;
        for(auto child:adj[node]){
            if(child==par) continue;
            sum += dfs(child,node);
        }

        if(node!=0) ans += (ceil(sum*1.0/s));
        return sum;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        s = seats;
        int n = roads.size()+1;
        adj.resize(n+1);
        for(auto &e:roads){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1);
        return ans;
    }
};