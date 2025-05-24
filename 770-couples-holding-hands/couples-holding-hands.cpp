class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[row[i]] = i;
        }

        int cnt = 0;
        for(int i=0; i<n; i += 2){
            if(row[i]%2){
                if(row[i+1]==row[i]-1) continue;
                else {
                    int i1 = i+1;
                    int i2 = mp[row[i]-1];
                    mp[row[i]-1] = i1;
                    mp[row[i+1]] = i2;
                    swap(row[i1],row[i2]);
                    cnt++;
                }
            }else{
                if(row[i+1] == row[i]+1) continue;
                else{
                    int i1 = i+1;
                    int i2 = mp[row[i]+1];
                    mp[row[i]+1] = i1;
                    mp[row[i+1]] = i2;
                    swap(row[i1],row[i2]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};