class Solution {
    vector<vector<int>>adj;
    vector<int>ans;
    int f(int person,vector<int>& quiet){
        int per = person;
        if(ans[per]!=-1) return ans[per];
        for(auto richer:adj[person]){
            int rich = f(richer,quiet);
            if(quiet[per]>quiet[rich]){
                per = rich;
            }
        }
        return ans[person] = per;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        adj.resize(n);
        ans.resize(n,-1);
        vector<int>ind(n,0);
        for(auto e:richer){
            adj[e[1]].push_back(e[0]);
            ind[e[0]]++;
        }
        for(int i=0;i<n; i++){
            if(ind[i]==0){
                f(i,quiet);
            }
        }
        return ans;
    }
};