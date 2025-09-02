class Solution {
    bool f(int i,int j,vector<vector<int>>&p){
        int n = p.size();
        int r1 = p[i][0],c1 = p[i][1];
        int r2 = p[j][0],c2 = p[j][1];
        for(int k=0;k<n; k++){
            if(k!=i && k!=j){
                int r3 = p[k][0],c3 = p[k][1];
                if(r3<=r2 && r3>=r1 && c3<=c1 && c3>=c2) return false;
            }
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();
        int ans = 0;
        for(int i=0;i<n; i++){
            for(int j=0; j<n; j++){
                int r1 = p[i][0],c1 = p[i][1];
                int r2 = p[j][0],c2 = p[j][1];

                if(i!=j && r2>=r1 && c2<=c1){
                    if(f(i,j,p)) ans++;
                }
                
            }
        }
        return ans;
    }
};