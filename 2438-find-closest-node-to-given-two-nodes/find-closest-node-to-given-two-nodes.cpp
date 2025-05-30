class Solution {
    vector<vector<int>>adj;
    vector<int>vis;
    vector<pair<int,int>>dist;

    void f(int node,int dis){
        vis[node] = 1;
        
        for(auto child:adj[node]){
            if(vis[child]==0){
                f(child,dis+1);
            }
        }
        vis[node] = 2;
        dist[node].first = max(dis,dist[node].first);
        cout<<dist[node].first<<endl;
        dist[node].second++;
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        adj.resize(n);
        vis.resize(n,0);
        dist.resize(n,{-1,0});
        
        for(int i=0; i<n; i++){
            if(edges[i]==-1) continue;
            adj[i].push_back(edges[i]);
        }

        f(node1,0);
        fill(vis.begin(), vis.end(), 0);
        f(node2,0);
        int minidx = -1, mindist = 1e9;
        for(int i=0; i<n; i++){
            if(dist[i].second==2 && dist[i].first < mindist){
                minidx = i;
                mindist = dist[i].first;
            }
        }
        return minidx;
    }   
};