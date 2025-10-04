class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& edges, vector<int>& t) {
        vector<vector<int>>adj(n);
        vector<int>dist(n,0),ind(n,0),out(n,0);

        for(auto e:edges){
            adj[e[0]-1].push_back(e[1]-1);
            ind[e[1]-1]++;
            out[e[0]-1]++;
        }
        // dist,node
        int sum = 0;
        queue<tuple<int,int>>q;
        for(int i=0; i<n; i++){
            if(ind[i]==0){
                q.push({t[i],i});
            }
        }

        while(!q.empty()){
            auto [dis,node] = q.front();
            q.pop();
            sum = max(sum,dis);

            for(auto adjnode:adj[node]){
                int newdist = dis+t[adjnode];
                dist[adjnode] = max(dist[adjnode],newdist);
                ind[adjnode]--;
                if(ind[adjnode]==0) q.push({dist[adjnode],adjnode});
            }
        }

        // for(int i=0; i<n; i++){
        //     if(out[i]==0){
        //         sum += t[i];
        //     }
        // }
        return sum;
    }
};