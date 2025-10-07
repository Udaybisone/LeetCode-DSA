class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        int n = r.size();
        unordered_map<int,int>vis;
        set<int>zeros;
        vector<int>ans(n,-1);
        int k = -1;
        for(int i=0; i<n; i++){
            if(r[i]==0) {
                zeros.insert(i);
                continue;
            }
            if(vis.find(r[i])==vis.end() || vis[r[i]]==-1) {
                vis[r[i]] = i;
            }
            else{
                auto it = zeros.lower_bound(vis[r[i]]);
                if(it==zeros.end()) return {};
                else{
                    ans[*it] = r[i];
                    vis[r[i]] = i;
                    zeros.erase(it);
                }
            }
        }

        for(auto it:zeros){
            ans[it] = 1;
        }

        return ans;
    }
};