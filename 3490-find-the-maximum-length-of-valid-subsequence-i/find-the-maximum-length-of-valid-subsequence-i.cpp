class Solution {
public:
    int maximumLength(vector<int>& nums) {
       
        int n = nums.size();
        int zero=0,one = 0 ,alt = 1, pre = nums[0]%2;
        
        for(int i=0; i<n; i++){
            int ele = nums[i]%2;
            if(ele==0) zero++;
            else one++;
            
            if(ele!=pre){
                alt++;
                pre = ele;
            }
        }
        
        int ans = max(alt,max(zero,one));
        return ans;
    }
};