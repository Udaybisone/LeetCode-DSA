class Solution {
    int f(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int,int> mp;
    int cnt = 0, left = 0;
    
    for(int right = 0; right < n; right++){
        if(mp[nums[right]] == 0) k--;
        mp[nums[right]]++;

        while(k < 0){
            mp[nums[left]]--;
            if(mp[nums[left]] == 0) k++;
            left++;
        }

        cnt += (right - left + 1); 
    }
    return cnt;
}

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        int AtMostK = f(nums,k);
        int AtMostKm1 = f(nums,k-1);
        int ans = AtMostK - AtMostKm1;
        return ans;

    }
};