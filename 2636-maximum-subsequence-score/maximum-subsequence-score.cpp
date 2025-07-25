class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<long long ,long long>>v;
        for(int i=0; i<n; i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<>>pq;
        long long sum = 0,res = 0;
        for(int i=n-1; i>=0; i--){
            if(pq.size()<k){
                pq.push(v[i].second);
                sum += v[i].second;
            }else if(pq.top()<v[i].second){
                sum -= pq.top();
                pq.pop();
                pq.push(v[i].second);
                sum += v[i].second;
            }
            v[i].second = sum;
        }
        
        for(int i=0; i<=n-k; i++){
            res = max(res,v[i].first*v[i].second);
        }
        // cout<<v[i].first<<" "<<v[i]
        return res;
    }
};