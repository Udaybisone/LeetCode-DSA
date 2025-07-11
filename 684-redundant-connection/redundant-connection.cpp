class Solution {
    struct dsu{
        vector<int>par,size;
        dsu(int n){
            par.resize(n+1);
            size.resize(n+1,1);
            for(int i=0; i<=n; i++) par[i] = i;
        }

        int findUPar(int node){
            if(par[node]==node) return node;
            return par[node] = findUPar(par[node]);
        }

        void unit(int u,int v){
            int upar = findUPar(u);
            int vpar = findUPar(v);
            if(upar==vpar) return;
            if(size[upar] > size[vpar]){
                size[upar] += size[vpar];
                par[vpar] = upar; 
            }else{
                size[vpar] += size[upar];
                par[upar] = vpar;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n  = edges.size();
        dsu ds(n);
        for(auto &e:edges){
            int u = e[0], v = e[1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                ans = {u,v};
            }
            ds.unit(u,v);
        }
        return ans;
    }
};