class Solution {
public:
    int hIndex(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n-1;
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            int len = n - mid;
            ans = max(ans,min(v[mid],len));

            if(v[mid] >= len) r = mid-1;
            else l = mid+1;
        }
        return ans;
    }
};