class Solution {
    
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n,INT_MAX);
        dist[0] = 0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // dist,node
        queue<tuple<int,int>>q;

        q.push({0,0});

        while(!q.empty()){
           auto [dis,node] = q.front();
           q.pop();

           for(auto [adjnode,cnt]:adj[node]){
                if(dis+cnt+1 <= maxMoves && dis+cnt+1 < dist[adjnode]){
                    dist[adjnode] = dis + cnt + 1;
                    q.push({dist[adjnode],adjnode});
                }
           }
        }

        int ans = 0;
        for(int node=0; node<n; node++){
            if(dist[node] <= maxMoves) ans++;
            cout<<dist[node]<<endl;
        }
        for(auto it:edges){
            int fd = dist[it[0]];
            int sd = dist[it[1]];
            int cnt = it[2];
            
            int total = 0;
            if(fd!=INT_MAX) total += (maxMoves-fd);
            if(sd!=INT_MAX) total += (maxMoves-sd);
            ans += min(cnt,total);
        }
        return ans;
    }
};