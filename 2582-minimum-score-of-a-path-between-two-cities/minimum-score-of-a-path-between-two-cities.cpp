class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int>dist(n+1,1e9);
        queue<tuple<int,int>>q;
        q.push({1e9,1});

        while(!q.empty()){
            auto [dis,node] = q.front();
            q.pop();

            for(auto &nb:adj[node]){
                int adjnode = nb.first;
                int wt = nb.second;

                if(dist[adjnode] > min(dis,wt)){
                    dist[adjnode] = min(dis,wt);
                    q.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist[n];
    }
};