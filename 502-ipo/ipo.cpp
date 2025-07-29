class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pf, vector<int>& cp) {
        int n = pf.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({cp[i],pf[i]});
        }

        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int i = 0;
        while(k--){
            while(i<n && v[i].first <= w) pq.push(v[i++].second);
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }else break;
        }
        return w;
    }
};