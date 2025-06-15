class Solution {
    struct DSU {
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }

        int find(int x) {
            if (x == parent[x])
                return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return;

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }

        bool connected(int u, int v) {
            return find(u) == find(v);
        }
    };

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m<n-1) return -1;
        DSU ds(n);
        for(auto e:connections){
            ds.unite(e[0],e[1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            // cout<<ds.parent[i]<<" ";
            if(ds.parent[i]==i) ans++;
        }
        return ans-1;
    }
};