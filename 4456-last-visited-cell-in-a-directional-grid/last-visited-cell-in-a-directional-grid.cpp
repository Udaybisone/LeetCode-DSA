class Solution {
    int ansL = 0,ansR = 0;
    int n , m;
    vector<vector<bool>> vis;
    void f(int i,int j,vector<vector<char>>&grid){

        vis[i][j] = true;

        int ni = i, nj = j;

        if (grid[i][j] == 'R') nj++;
        else if (grid[i][j] == 'L') nj--;
        else if (grid[i][j] == 'U') ni--;
        else if (grid[i][j] == 'D') ni++;

        if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj]) {
            ansL = i;
            ansR = j;
            return;
        }

        f(ni, nj, grid);
    }
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<bool>(m, false));

        f(0,0,grid);
        return {ansL,ansR};
    }
};