class Solution {
public:
    int totalFruit(vector<int>& fr) {
        int n = fr.size();
        int r = 0;
        int res = 0;
        unordered_map<int,int>mp;
        int sz = 0;
        for(int l=0; l<n; l++){
            while(r<n && sz<=2){
                if(!mp.count(fr[r])){
                    if(sz == 2) break;
                    else{
                        sz++;
                        mp[fr[r]]++;
                        res = max(res,r-l+1);
                        r++;
                    }
                }else{
                    mp[fr[r]]++;
                    res = max(res,r-l+1);
                    r++;
                }
            }
            mp[fr[l]]--;
            if(mp[fr[l]]==0){
                sz--;
                mp.erase(fr[l]);
            }
        }
        return res;
    }
};