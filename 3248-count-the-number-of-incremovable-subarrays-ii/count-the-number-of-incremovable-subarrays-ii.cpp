#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int r = n-1;

        while(r>0){
            if(nums[r]<=nums[r-1]){
                break;
            }
            r--;
        }
        long long ans = n - ((r>0)?r-1:r);
        cout<<ans<<endl;
        for(int i=1; i<n; i++){
            if(i>=2 && nums[i-1]<=nums[i-2]) break;
            int idx = upper_bound(nums.begin()+max(r,i+1),nums.end(),nums[i-1])-nums.begin();
            // if()
            ans += (n-(idx-1));
        }
        return ans;
        
    }
};