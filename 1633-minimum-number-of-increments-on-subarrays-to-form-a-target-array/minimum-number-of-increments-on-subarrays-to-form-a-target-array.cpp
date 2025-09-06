class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int mini = 0;

        int prev = 0;
        int add = 0;
        for(int i=0; i<n; i++){

            if(prev<=v[i]) {
                prev = v[i];
                add = v[i];
            }
            else{
                ans += (prev - mini);
                prev = 0;
                mini = v[i];
                add = 0;
            }
            if(v[i]<=mini) mini = v[i];

        }
        if(add!=0) ans += (add-mini);
        return ans;
    }
};