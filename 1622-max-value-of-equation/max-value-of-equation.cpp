class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pt, int k) {
        int n = pt.size();
        priority_queue<pair<int,int>>pq;
        int ans = INT_MIN;
        for(auto it:pt){
            int x = it[0];
            int y = it[1];
            while(!pq.empty() && (x - pq.top().second)>k) pq.pop();
            
            if(!pq.empty()){
                ans = max(ans,x+y+pq.top().first);
            }
            pq.push({y-x,x});
        }   
        return ans;
    }
};