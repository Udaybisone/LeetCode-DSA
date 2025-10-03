class Solution {
    vector<int> topo(vector<vector<int>>&edges,int &n){
        vector<vector<int>>adj(n+1);
        vector<int>ind(n+1,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }

        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=n; i++){
            if(ind[i]==0){
                ans.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjnode:adj[node]){
                ind[adjnode]--;
                if(ind[adjnode]==0){
                    ans.push_back(adjnode);
                    q.push(adjnode);
                }
            }
        }

        return ans;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<int>r = topo(rc,k);
        if(r.size()!=k) return {};
        vector<int>c = topo(cc,k);
        if(c.size()!=k) return {};

        vector<vector<int>>ans(k,vector<int>(k,0));

        unordered_map<int,pair<int,int>>mp;
        for(int i=0; i<k; i++){
            mp[r[i]].first = i;
            mp[c[i]].second = i;
        } 

       for(auto it:mp){
        ans[it.second.first][it.second.second] = it.first;
       }
       return ans;
    }
};