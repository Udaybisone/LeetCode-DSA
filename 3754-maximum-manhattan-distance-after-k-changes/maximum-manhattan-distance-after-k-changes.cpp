class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        vector<string>v = {"NE","NW","SE","SW"};
        int ans = 0;
        for(int i=0; i<4; i++){
            int k1 = k;
            int sum = 0;
            for(auto ch:s){
                if(ch==v[i][0] or ch==v[i][1]) sum++;
                else if(k1>0){
                    k1--;
                    sum++;
                }else {
                    ans = max(ans,sum);
                    sum--;
                }
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};