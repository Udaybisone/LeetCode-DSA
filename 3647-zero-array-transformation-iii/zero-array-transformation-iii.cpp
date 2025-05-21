class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        sort(q.begin(),q.end());
        priority_queue<int,vector<int>,greater<int>>minpq;
        priority_queue<int>maxpq;
        int j = 0;
        int m = q.size();
        for(int i=0; i<n; i++){
            while(!minpq.empty() && minpq.top() < i) minpq.pop();
            nums[i] -= minpq.size();
            int k = max(0,nums[i]);
            while(j<m && q[j][0]==i) maxpq.push(q[j++][1]);
            while(!maxpq.empty() && maxpq.top()>=i && k>0){
                minpq.push(maxpq.top());
                maxpq.pop();
                k--;
            }
            if(k>0) return -1;
        }
        return maxpq.size();
    }
};