class NumArray {
    vector<int>st;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        bt(0,n-1,1,nums);
    }

    void bt(int l, int r,int idx, vector<int>&nums){
        if(l==r) {
            st[idx] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;

        bt(l,mid,2*idx,nums);
        bt(mid+1,r,2*idx+1,nums);

        st[idx] = st[2*idx] + st[2*idx+1];
    }

    int getsum(int l,int r,int i,int left,int right){
        if(l>=left && r<=right) return st[i];
        if(r<left or l>right) return 0;

        int mid = l + (r-l)/2;

        return getsum(l,mid,2*i,left,right) + getsum(mid+1,r,2*i+1,left,right);
    }
    
    int sumRange(int left, int right) {
        return getsum(0,n-1,1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */