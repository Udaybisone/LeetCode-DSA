class Solution {
    struct DSU{
        vector<int>parent,size;
        DSU(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0; i<n; i++) parent[i] = i;
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int u,int v){
            int pu = find(u);
            int pv = find(v);
            if(pu==pv) return ;

            if(size[pu]<size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }

        bool isconnected(int n){
            int c = 0;
            for(int i=0; i<n; i++){
                if(parent[i]==i) c++;
            }
            return c==1;
        }
    };
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lf, vector<int>& rt) {
        vector<int>ind(n,0);
        DSU ds(n);
        for(int i=0; i<n; i++){
            if(lf[i]!=-1) {
                ind[lf[i]]++;
                ds.unite(i,lf[i]);
            }
            if(rt[i]!=-1) {
                ind[rt[i]]++;
                ds.unite(i,rt[i]);
            }
        }
        int zero = 0;
        for(auto it:ind){
            if(it==0) zero++;
            if(it>1) return false;
        }
        if(zero!=1) return false;
        return ds.isconnected(n);
    }
};