class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector<vector<int>>radj(n),badj(n);
        vector<vector<int>>dist(n,vector<int>(2,1e9));

        for(auto &e:re){
            radj[e[0]].push_back(e[1]);
        }
        for(auto &e:be){
            badj[e[0]].push_back(e[1]);
        }

        dist[0][1] = 0;
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        // dis,node,prev
        pq.push({0,0,0});
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [dis,node,prev] = pq.top();
            pq.pop();

            vector<vector<int>>adj = (prev==1)?radj:badj;

            for(auto nb:adj[node]){
                if(dist[nb][prev]>dis+1){
                    dist[nb][prev] = dis+1;
                    
                    pq.push({dis+1,nb,1-prev});
                }
            }
        }

        vector<int>ans(n,1e9);
        for(int i=0; i<n; i++){
            ans[i] = min(dist[i][1],dist[i][0]);
            if(ans[i]==1e9) ans[i] = -1;
        }
        return ans;
    }
};