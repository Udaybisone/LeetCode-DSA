class Solution {
    vector<vector<string>>res;
    void f(int row,vector<vector<int>>&grid){
        int n = grid.size();
        if(row==n) {
            vector<string>vs;
            for(int i=0; i<n; i++){
                string s = "";
                for(int j=0; j<n; j++) s += ((grid[i][j]==1)?"Q":".");
                vs.push_back(s);
            }
            res.push_back(vs);
        }
        for(int col=0; col<n; col++){
            bool up = true, dr = true , dl = true;
            for(int i=0; i<row; i++){
                if(grid[i][col]==1) {
                    up = false;
                    break;
                }
            }
            if(!up) continue;
            int i = row-1 , j = col-1;
            while(i>=0 && j>=0){
                if(grid[i][j]==1){
                    dl = false;
                    break;
                }
                i--,j--;
            }
            if(!dl) continue;
            i = row-1 , j = col+1;
            while(i>=0 && j<n){
                if(grid[i][j]==1){
                    dr = false;
                    break;
                }
                i--,j++;
            }
            if(!dr) continue;
            grid[row][col] = 1;
            f(row+1,grid);
            grid[row][col] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        f(0,grid);
        return res;
    }
};