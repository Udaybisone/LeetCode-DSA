#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> deg(n+1,0);
        map<pair<int,int>,int> cnt;

        // 1. store degrees and edge counts
        for (auto &e: edges) {
            int u=e[0], v=e[1];
            deg[u]++; deg[v]++;
            if (u>v) swap(u,v);
            cnt[{u,v}]++;
        }

        // 2. sort degrees
        vector<int> sorted(deg.begin()+1, deg.end());
        sort(sorted.begin(), sorted.end());

        vector<int> ans;

        for (int q: queries) {
            long long total=0;

            // 3. count pairs using lower_bound
            for (int i=0;i<n;i++) {
                int need = q - sorted[i];
                auto it = upper_bound(sorted.begin()+i+1, sorted.end(), need);
                total += (sorted.end()-it);
            }

            // 4. correct with multi-edges
            for (auto &p: cnt) {
                int u=p.first.first, v=p.first.second, c=p.second;
                if (deg[u]+deg[v] > q && deg[u]+deg[v]-c <= q) total--;
            }

            ans.push_back((int)total);
        }

        return ans;
    }
};