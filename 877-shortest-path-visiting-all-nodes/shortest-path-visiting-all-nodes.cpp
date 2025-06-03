class Solution {
    vector<vector<int>>dist;
    int goal=0;
    int f(int start,vector<vector<int>>& adj){
        int n = adj.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,start,(1<<start)});
        dist[start][(1<<start)] = 0;

        while(!pq.empty()){
            auto [dis,node,bitmask] = pq.top();
            pq.pop();
            if(bitmask==goal) return dis;

            for(auto child:adj[node]){
                int newdis = dis+1;
                int newbitmask = (bitmask | (1<<child));
                if(dist[child][newbitmask]>newdis){
                    dist[child][newbitmask] = newdis;
                    pq.push({newdis,child,newbitmask});
                }
            }
        }
        return 1e9;
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0; i<n; i++) goal += (1<<i);
        dist.resize(n+1,vector<int>(goal+1,1e9));
        int ans = 1e9;
        for(int node=0;node<n; node++){
            int dist = f(node,graph);
            if(dist<ans) ans = dist;
        }
        return ans;
    }
};