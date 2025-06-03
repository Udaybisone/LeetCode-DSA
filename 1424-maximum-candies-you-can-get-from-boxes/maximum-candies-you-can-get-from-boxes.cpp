class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int>q;
        vector<int>closed(n,0);
        vector<int>vis(n,0);
        for(auto box:initialBoxes){
            if(status[box]) q.push(box);
            else closed[box] = 1;
        }
        int res = 0;
        while(!q.empty()){
            int box = q.front();
            q.pop();
            vis[box] = 1;
            res += candies[box];
            for(auto inbox:keys[box]){
                status[inbox] = 1;
                if(closed[inbox]){
                    q.push(inbox);
                    closed[inbox] = 0;
                }
            }
            for(auto inbox:containedBoxes[box]){
                if(!vis[inbox]){
                    if(status[inbox]){
                        q.push(inbox);
                    }else closed[inbox] = 1;
                }
            }
        }
        return res;
    }
};