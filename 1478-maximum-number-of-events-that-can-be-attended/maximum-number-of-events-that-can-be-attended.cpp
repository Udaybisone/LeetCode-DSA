class Solution {
public:
    int maxEvents(vector<vector<int>>& v) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(v.begin(), v.end());
        int n = v.size();
        int day = v[0][0];
        int i = 0, cnt = 0;

        while(!pq.empty() || i<n) {
            while (i < n && v[i][0] == day){
                pq.push(v[i][1]);
                i++;
            }

            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }
            day++;
            while (!pq.empty() && pq.top() < day)
                pq.pop();
                
        }

        return cnt;
    }
};
