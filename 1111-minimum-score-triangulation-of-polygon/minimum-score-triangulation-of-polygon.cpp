class Solution {
    vector<vector<int>>dp;
    int f(int i,int j,vector<int>&v){
        if(j-i+1 == 3){
            return (v[i]*v[i+1]*v[j]);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            int temp = (v[i]*v[k]*v[j]) + f(i,k,v) + f(k,j,v);
            ans = min(ans,temp);
        }
        return dp[i][j] = (ans==INT_MAX?0:ans);
    }
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans = f(0,n-1,v);
        return ans;
    }
};