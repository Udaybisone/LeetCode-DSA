class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& pl, vector<int>& tr) {
        
        int n = pl.size(),m = tr.size();
        sort(pl.begin(),pl.end());
        sort(tr.begin(),tr.end());
        int i = 0, j = 0;
        while(i<n && j<m){
            if(pl[i]<=tr[j]) {
                i++;
            }
            j++;
        } 
        return i;
    }
};