class Solution {
    struct dsu {
        vector<int> par, size;
        dsu(int n) {
            par.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        int findUPar(int node) {
            if (par[node] == node) return node;
            return par[node] = findUPar(par[node]);
        }

        void combine(int u, int v) {
            int upar = findUPar(u);
            int vpar = findUPar(v);
            if (upar == vpar) return;
            if (size[upar] > size[vpar]) {
                size[upar] += size[vpar];
                par[vpar] = upar;
            } else {
                size[vpar] += size[upar];
                par[upar] = vpar;
            }
        }
    };

    static bool comp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

   int krushkal(int skip, int add, vector<vector<int>>& e, int k) {
    int wt = 0;
    dsu ds(k);
    int edgesUsed = 0;

    if (add != -1) {
        if (ds.findUPar(e[add][0]) != ds.findUPar(e[add][1])) {
            ds.combine(e[add][0], e[add][1]);
            wt += e[add][2];
            edgesUsed++;
        }
    }

    for (int i = 0; i < e.size(); i++) {
        if (i == skip) continue;
        if (ds.findUPar(e[i][0]) != ds.findUPar(e[i][1])) {
            ds.combine(e[i][0], e[i][1]);
            wt += e[i][2];
            edgesUsed++;
        }
    }

    // Return INT_MAX to indicate not a valid MST
    if (edgesUsed < k - 1) return INT_MAX;
    return wt;
}


public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int k, vector<vector<int>>& e) {
        vector<int> ce, pce;
        int n = e.size();
        for (int i = 0; i < n; i++) {
            e[i].push_back(i); // Store original index
        }
        sort(e.begin(), e.end(), comp);
        int mstwt = krushkal(-1, -1, e, k);
        for (int i = 0; i < n; i++) {
            int skipwt = krushkal(i, -1, e, k);
            int addwt = krushkal(-1, i, e, k);
            if (skipwt > mstwt) ce.push_back(e[i][3]);
            else if (addwt == mstwt) pce.push_back(e[i][3]);
        }
        return {ce, pce};
    }
};
