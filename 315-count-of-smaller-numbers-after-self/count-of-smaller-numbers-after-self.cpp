class Solution {
    vector<int>ans;
    static bool comp(const pair<int,int>& p, int value) {
        return p.first < value;
    }
    vector<pair<int,int>> f(int l,int r,vector<int>&nums){
        if(l==r) return {{nums[l],l}};

        int mid = l + (r-l)/2;
        vector<pair<int,int>>left = f(l,mid,nums);
        vector<pair<int,int>>right = f(mid+1,r,nums);

        for(auto [v,i]:left){
            int idx = lower_bound(right.begin(),right.end(),v,comp) - right.begin();
            ans[i] += idx;
        }

        vector<pair<int,int>>merge;
        int i = 0, j = 0, n = left.size(), m = right.size();

        while(i<n && j<m){
            if(left[i].first > right[j].first) merge.push_back({right[j].first,right[j++].second});
            else merge.push_back({left[i].first,left[i++].second});
        }
        while(i<n) merge.push_back({left[i].first,left[i++].second});
        while(j<m) merge.push_back({right[j].first,right[j++].second});

        return merge;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n,0);

        f(0,n-1,nums);

        return ans;
    }
};