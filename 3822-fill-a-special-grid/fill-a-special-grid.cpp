class Solution {
    vector<vector<int>>grid;
    void f(int r1,int r2,int c1,int c2,int l,int r){
        if(c1==c2){
            grid[r1][c1] = l;
            return;
        }

        int midr = (r2+r1)/2;
        int midc = (c1+c2)/2;
        int k = (r-l+1)/4;
        f(r1,midr,midc+1,c2,l,l+k-1);
        f(midr+1,r2,midc+1,c2,l+k,l+2*k-1);
        f(midr+1,r2,c1,midc,l+2*k,l+3*k-1);
        f(r1,midr,c1,midc,l+3*k,r);
    }
public:
    vector<vector<int>> specialGrid(int n) {
        int m = 1;
        for(int i=0; i<n;i++) m *= 2;
        int l = 0, r = m*m;

        grid.resize(m,vector<int>(m,0));
        f(0,m-1,0,m-1,0,r-1);
        return grid;
    }
};