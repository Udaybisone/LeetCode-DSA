class Solution {
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;

    void help(int i,int &cost,vector<vector<int>>&cos,int f,int &n,int &m,int &r,int &c){
        if(i==1 && c+1<m && cos[r][c+1]>cost+f) {
            pq.push({cost+f,r,c+1});
            cos[r][c+1] = cost+f;
        }
        if(i==2 && c-1>=0 && cos[r][c-1]>cost+f) {
            pq.push({cost+f,r,c-1});
            cos[r][c-1] = cost+f;
        }
        if(i==3 && r+1<n && cos[r+1][c]>cost+f){
            pq.push({cost+f,r+1,c});
            cos[r+1][c] = cost+f;
        }
        if(i==4 && r-1>=0 && cos[r-1][c]>cost+f){
            pq.push({cost+f,r-1,c});
            cos[r-1][c] = cost+f;
        }
    }
public:
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>cos(n,vector<int>(m,INT_MAX));

        // cost,i,j

        pq.push({0,0,0});
        cos[0][0] = 0;

        while(!pq.empty()){
            auto [cost,r,c] = pq.top();
            pq.pop();

            if(r<0 or c<0 or r>=n or c>=m) continue;

            if(r==n-1 && c == m-1) return cost;

            for(int i=1; i<=4; i++){
                if(grid[r][c] == i){
                    help(i,cost,cos,0,n,m,r,c);
                }else{
                    help(i,cost,cos,1,n,m,r,c);
                }
            }
        }
        return -1;
    }
};