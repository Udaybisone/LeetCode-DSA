class Solution {
public:
    bool checkMove(vector<vector<char>>& v, int rMove, int cMove, char color) {
        int n = v.size(), m = v[0].size();
        char opp = (color == 'W' ? 'B' : 'W');
        int dx[8] = {0,1,1,1,0,-1,-1,-1}, dy[8] = {1,1,0,-1,-1,-1,0,1};
        
        for (int k = 0; k < 8; k++) {
            int x = rMove + dx[k], y = cMove + dy[k], cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == opp) {
                cnt++; x += dx[k]; y += dy[k];
            }
            if (cnt > 0 && x >= 0 && x < n && y >= 0 && y < m && v[x][y] == color)
                return true;
        }
        return false;
    }
};
