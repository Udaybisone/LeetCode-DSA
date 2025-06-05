class Solution {
    class DisjointSet {
        vector<int> parent; 
public: 
        DisjointSet(int n) {
            parent.resize(n+1);
            for(int i = 0;i<=n;i++) {
                parent[i] = i; 
            }
        }

        int findUPar(int node) {
            if(node == parent[node])
                return node; 
            return parent[node] = findUPar(parent[node]); 
        }

        void unionBySmallChar(int u, int v) {
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return; 
            if(ulp_u < ulp_v) {
                parent[ulp_v] = ulp_u; 
            }
            else {
                parent[ulp_u] = ulp_v;
            }
        }
    }; 
public:
    string smallestEquivalentString(string s, string t, string baseStr) {
        DisjointSet ds(26);
        int n = s.size(); 
        for(int i=0; i<n; i++){
            ds.unionBySmallChar(s[i]-'a',t[i]-'a');
        }
        string ans = "";
        for(auto ch:baseStr){
            ans += (ds.findUPar(ch-'a')+'a');
        }
        return ans;
    }
};