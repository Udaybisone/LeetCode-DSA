class FindSumPairs {
    vector<int>nums1;
    unordered_map<int,int>mp;
    unordered_map<int,int>freq2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        int n = nums2.size();
        for(int i=0; i<n; i++){
            mp[i] = nums2[i];
            freq2[nums2[i]]++;
        }
    }
    
    void add(int idx, int val) {
        freq2[mp[idx]]--;
        freq2[val+mp[idx]]++;
        mp[idx] += val;
    }
    
    int count(int tot) {
        int ans = 0;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            ans += freq2[tot-nums1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */