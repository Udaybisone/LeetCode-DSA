class Solution {
    int cnt = 0;
    vector<int> f(int i,int j,vector<int>&nums){

        if(i==j) return {nums[i]};

        int mid = i + (j-i)/2;

        vector<int>a = f(i,mid,nums);
        vector<int>b = f(mid+1,j,nums);

        int n = a.size(),m = b.size();;
        for(auto &ele:b){
            long long idx = upper_bound(a.begin(),a.end(),2LL*(long long)ele) - a.begin();
            cnt += (n - idx);
            // cout<<"a: ";
            // for(auto it:a) cout<<it<<" ";
            // cout<<endl<<"b: ";
            // for(auto it:b) cout<<it<<" ";
            // cout<<endl;
            // cout<<(n-idx)<<endl;
        }
        vector<int>c;
        int l = 0, r = 0;
        while(l<n && r<m){
            if(a[l]<b[r]) c.push_back(a[l++]);
            else c.push_back(b[r++]);
        }

        while(l<n) c.push_back(a[l++]);
        while(r<m) c.push_back(b[r++]);

        return c;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        f(0,n-1,nums);

        return cnt;
    }
};