class Solution {
    
    vector<vector<int>>adj;
    vector<int>vis;
    void dfs(int node, int dis, vector<int>&dist){
        dist[node] = dis;
        vis[node] = 1;
        for(auto child:adj[node]){
            if(vis[child]) continue;
            dfs(child,dis+1,dist);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n,-1),dist2(n,-1);
        adj.resize(n);

        for(int i=0; i<n; i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vis.resize(n,0);
        dfs(node1,0,dist1);
        for(int i=0; i<n; i++) vis[i] = 0;
        dfs(node2,0,dist2);
        int ans = 1e9;
        int node = -1;

        for(int i=0; i<n; i++){
            if(dist1[i]!=-1 && dist2[i]!=-1 && ans>max(dist1[i],dist2[i])){
                ans = max(dist1[i],dist2[i]);
                node = i;
            }
        }
        return node;
    }
};