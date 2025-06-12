class NumArray {
    vector<int>nums;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        for(int i=1; i<n; i++) nums[i] += nums[i-1];
        this->nums = nums;
    }
    
    int sumRange(int l, int r) {
        return nums[r] - ((l==0)?0:nums[l-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */