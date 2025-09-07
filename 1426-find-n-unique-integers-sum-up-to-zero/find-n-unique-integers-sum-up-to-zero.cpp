class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        for(int i=(0-n)/2; i<=n/2; i++){
            if(!(n%2) && i==0) continue;
            ans.push_back(i);
        }
        return ans;
    }
};