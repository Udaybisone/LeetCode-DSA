class Solution {
    vector<vector<int>>adj;
    vector<int>parant;
    vector<int>vis;
    vector<int>subtreesum;
    vector<int>noOfNodes;
    // non,sum
    pair<int,int> calcsum(int node){
        vis[node] = 1;
        int non = 0;
        int tsum = 0;
        for(auto child:adj[node]){
            if(!vis[child]){
                parant[child] = node;
                auto childcall = calcsum(child);
                non += childcall.first;
                int sum = childcall.second;
                tsum += (sum+childcall.first);
            }
        }
        subtreesum[node] = tsum;
        noOfNodes[node] = non+1;
        return {non+1,tsum};
    }

    void dfs2(int node, int parent, vector<int>& ans, int n) {
        for (int child : adj[node]) {
            if (child != parent) {
                ans[child] = ans[node] - noOfNodes[child] + (n - noOfNodes[child]);
                dfs2(child, node, ans, n);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n+1);
        parant.resize(n,-1);
        vis.resize(n,0);
        subtreesum.resize(n,0);
        noOfNodes.resize(n,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        parant[0] = 0;
        calcsum(0);

        vector<int> ans(n, 0);
        ans[0] = subtreesum[0];
        dfs2(0, -1, ans, n);
        return ans;
    }
};