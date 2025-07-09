class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>>adj(n);
        vector<int>ind(n,0);

        for(auto e:v){
            adj[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }

        queue<int>q;
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(ind[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nb:adj[node]){
                ind[nb]--;
                if(ind[nb]==0){
                    q.push(nb);
                    ans.push_back(nb);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0; i<n; i++){
            if(ind[i]>0) return {};
        }
        return ans;
    }
};