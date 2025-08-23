class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0, ele = -1;

        for(int i=0; i<n; i++){
            if(cnt==0){
                cnt++;
                ele = nums[i];
                continue;
            }
            if(ele == nums[i]) cnt++;
            else cnt--;
        }
        return ele;
    }
};