class Solution {
    vector<int>subxor;
    vector<vector<int>>adj;
    vector<unordered_set<int>>v;
    void dfs(int node, int par, vector<int>&nums){
        subxor[node] = nums[node];
        v[node].insert(node);
        for(auto child:adj[node]){
            if(child==par) continue;
            dfs(child,node,nums);
            v[node].insert(v[child].begin(),v[child].end());
            subxor[node] ^= subxor[child];
        }
    }
    int res = INT_MAX;
    void dfs3(int node, int par, int &removedNode) {
    for (auto child : adj[node]) {
        if (child == par || child == removedNode) continue;

        if (v[child].find(removedNode) != v[child].end()) {
            int xorchild = subxor[child] ^ subxor[removedNode];
            int xornode = subxor[0] ^ subxor[child];
            int xorRemovedNode = subxor[removedNode];

            int xorrdiff = max({xornode, xorchild, xorRemovedNode}) - min({xornode, xorchild, xorRemovedNode});
            res = min(res, xorrdiff);
        } else {
            int xorchild = subxor[child];
            int xornode = subxor[0] ^ subxor[child] ^ subxor[removedNode];
            int xorRemovedNode = subxor[removedNode];

            int xorrdiff = max({xornode, xorchild, xorRemovedNode}) - min({xornode, xorchild, xorRemovedNode});
            res = min(res, xorrdiff);
        }

        dfs3(child, node, removedNode);
    }
}



    void dfs2(int node, int par){
        for(auto child:adj[node]){
            if(child==par) continue;
            dfs3(0,-1,child);
            dfs2(child,node);
        }
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        subxor.resize(n);
        adj.resize(n);
        v.resize(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,nums); // create subxor
        dfs2(0,-1);
        return res;
    }
};