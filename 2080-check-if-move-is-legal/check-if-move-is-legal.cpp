class Solution {
public:
    bool checkMove(vector<vector<char>>& v, int rMove, int cMove, char color) {
        int n = v.size(), m = v[0].size();
        char opp = (color == 'W' ? 'B' : 'W');
        int cnt;
        
        cnt = 0;
        for (int j = cMove + 1; j < m; j++) {
            if (v[rMove][j] == opp) { cnt++; continue; }
            if (v[rMove][j] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        cnt = 0;
        for (int j = cMove - 1; j >= 0; j--) {
            if (v[rMove][j] == opp) { cnt++; continue; }
            if (v[rMove][j] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        cnt = 0;
        for (int i = rMove + 1; i < n; i++) {
            if (v[i][cMove] == opp) { cnt++; continue; }
            if (v[i][cMove] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        cnt = 0;
        for (int i = rMove - 1; i >= 0; i--) {
            if (v[i][cMove] == opp) { cnt++; continue; }
            if (v[i][cMove] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        cnt = 0;
        int i = rMove - 1, j = cMove - 1;
        while (i >= 0 && j >= 0) {
            if (v[i][j] == opp) { cnt++; i--; j--; continue; }
            if (v[i][j] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        cnt = 0;
        i = rMove + 1; j = cMove - 1;
        while (i < n && j >= 0) {
            if (v[i][j] == opp) { cnt++; i++; j--; continue; }
            if (v[i][j] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        cnt = 0;
        i = rMove + 1; j = cMove + 1;
        while (i < n && j < m) {
            if (v[i][j] == opp) { cnt++; i++; j++; continue; }
            if (v[i][j] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        cnt = 0;
        i = rMove - 1; j = cMove + 1;
        while (i >= 0 && j < m) {
            if (v[i][j] == opp) { cnt++; i--; j++; continue; }
            if (v[i][j] == color) { if (cnt >= 1) return true; else break; }
            break;
        }
        
        return false;
    }
};
