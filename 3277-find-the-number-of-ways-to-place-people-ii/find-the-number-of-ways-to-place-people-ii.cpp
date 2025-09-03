class Solution {
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(),p.end(),cmp);
        // for(auto it:p){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        int ans = 0;
        int x = INT_MAX, y = INT_MAX;
        for(int i=0; i<n; i++){
            y = INT_MIN;
            for(int j=i+1; j<n; j++){
                if(p[j][1]<=y or p[j][1]>p[i][1]) continue;
                ans++;
                // cout<<i<<","<<j<<" "<<y<<endl;
                y = max(y,p[j][1]);
            }
        }

        return ans;
    }
};