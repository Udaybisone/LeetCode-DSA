class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = -1;
        int sum = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==-1){
                if(idx==-1) idx = i;
                else {
                    sum += (i-idx);
                    idx = -1;
                }
            }
        }
        if(idx==-1 && sum<=k){
            //  cout<<sum<<endl;
             return true;
        }
        sum = 0;
        idx = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                if(idx==-1) idx = i;
                else {
                    sum += (i-idx);
                    idx = -1;
                }
            }
        }
        if(idx==-1 && sum<=k){
             return true;
        }
        return false;
    }
};