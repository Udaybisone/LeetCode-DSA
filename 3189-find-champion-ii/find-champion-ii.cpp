class Solution {
public:
    int findChampion(int n, vector<vector<int>>& e) {
        vector<int>ind(n,0);

        for(auto it:e){
            ind[it[1]]++;
        }
        int champ = -1;
        for(int i=0; i<n; i++){
            if(ind[i]==0){
                if(champ == -1) champ = i;
                else return -1;
            }
        }
        return champ;
    }
};