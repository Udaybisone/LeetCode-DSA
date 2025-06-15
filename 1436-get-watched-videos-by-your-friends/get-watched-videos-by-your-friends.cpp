class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& adj, int id, int level) {
        int n = adj.size();
        queue<int>q;
        q.push(id);
        vector<int>vis(n,0);
        vis[id] = 1;
        while(level--){
            int m = q.size();
            for(int i=0;i<m; i++){
                int node = q.front();
                q.pop();
                for(auto f:adj[node]){
                    if(!vis[f]){
                        q.push(f);
                        vis[f] = 1;
                    }
                }
            }
        }
        vector<string>res;
        map<string,int>mp;
        while(!q.empty()){
            int person = q.front();
            q.pop();
            for(auto film:wv[person]) mp[film]++;
        }
        vector<pair<string, int>> videos(mp.begin(), mp.end());
        sort(videos.begin(),videos.end(),[](const auto&a,const auto&b){
            return a.second == b.second?(a.first < b.first):(a.second<b.second);
        });

        for (const auto& [video, _] : videos) {
            res.push_back(video);
        }

        return res;
    }
};