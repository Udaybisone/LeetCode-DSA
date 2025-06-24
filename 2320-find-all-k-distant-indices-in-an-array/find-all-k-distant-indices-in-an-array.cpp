class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int n = nums.size();
        vector<pair<int,int>>v(n,{-1,-1});
        if(nums[0]==key) v[0].first = 0;

        for(int i=1; i<n; i++){
            if(nums[i]==key){
                v[i].first = i;
            }else v[i].first = v[i-1].first;
        } 

        if(nums[n-1]==key) v[n-1].second = n-1;

        for(int i=n-2; i>=0; i--){
            if(nums[i]==key){
                v[i].second = i;

            }else v[i].second = v[i+1].second;
        }
        for(int i=0; i<n; i++){
            if((v[i].first!=-1 && abs(v[i].first-i)<=k) || (v[i].second !=-1 && abs(v[i].second-i)<=k)
            ) ans.push_back(i);
        }
        return ans;
    }
};