class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        int n = nums.size();
        int r = 0;
        while(r<k){
            while(!q.empty() && q.back()<nums[r]) q.pop_back();
            q.push_back(nums[r++]);
        }
        vector<int>ans;
        ans.push_back(q.front());
        for(r=r; r<n; r++){
            int l = r-k;
            if(q.front()==nums[l]) q.pop_front();
            while(!q.empty() && q.back()<nums[r]) q.pop_back();
            q.push_back(nums[r]);
            ans.push_back(q.front());
        }
        return ans;
    }
};