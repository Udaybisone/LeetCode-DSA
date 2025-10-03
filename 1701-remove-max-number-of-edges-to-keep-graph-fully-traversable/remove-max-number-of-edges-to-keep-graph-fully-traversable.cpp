class Solution {
    struct dsu {
        vector<int> par, size;

        dsu(int n) {
            par.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                par[i] = i;
            }
        }

        int findUPar(int node) {
            if (par[node] == node) return node;
            return par[node] = findUPar(par[node]); // Path compression
        }

        void combine(int u, int v) {
            int upar = findUPar(u);
            int vpar = findUPar(v);

            if (upar == vpar) return;

            if (size[upar] > size[vpar]) {
                par[vpar] = upar;
                size[upar] += size[vpar];
            } else {
                par[upar] = vpar;
                size[vpar] += size[upar];
            }
        }
    };

    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]>b[0];
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu a(n);
        dsu b(n);

        sort(edges.begin(),edges.end(),comp);
        int cnt = 0;
        for(auto it:edges){
            if(it[0]==1){
                if(a.findUPar(it[1])==a.findUPar(it[2])) cnt++;
                else a.combine(it[1],it[2]);
            }else if(it[0] == 2){
                if(b.findUPar(it[1])==b.findUPar(it[2])) cnt++;
                else b.combine(it[1],it[2]);
            }else{
                bool alice = (a.findUPar(it[1])==a.findUPar(it[2]));
                bool bob = (b.findUPar(it[1])==b.findUPar(it[2]));
                if(alice && bob) cnt++;
                else {
                    a.combine(it[1],it[2]);
                    b.combine(it[1],it[2]);
                }
            }
        }


        for(int i=2; i<=n; i++){
            if(a.findUPar(i)!=a.findUPar(1) || b.findUPar(i)!=b.findUPar(1)) return -1;
        }

        return cnt;
    }
};