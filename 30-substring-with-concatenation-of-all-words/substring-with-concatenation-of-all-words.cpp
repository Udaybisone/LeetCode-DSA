class Solution {
    vector<int>ans;
    void f(string &s,int idx,unordered_map<string,int>mp,int k,int &cnt){
        int n = s.size();
        int j = idx;
        int tempcnt = cnt;
        for(int i=idx; i<=n-k; i+=k){
            string str = s.substr(i,k);
            if(mp.find(str)==mp.end()){
                while(j<i){
                    string str2 = s.substr(j,k);
                    mp[str2]++;
                    j += k;
                }
                j += k;
                tempcnt = cnt;
            }else if(mp[str]==0){
                while(mp[str]==0){
                    string str2 = s.substr(j,k);
                    mp[str2]++;
                    tempcnt++;
                    j += k;
                }
                mp[str]--;
                tempcnt--;
            }else{
                mp[str]--;
                tempcnt--;
                if(tempcnt == 0){
                    ans.push_back(j);
                    string str2 = s.substr(j,k);
                    mp[str2]++;
                    j += k;
                    tempcnt++;
                }
            }
        }
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        unordered_map<string,int>mp;
        int k = words[0].size();
        for(auto word:words) mp[word]++;
        int cnt = words.size();
        
        for(int i=0; i<k; i++){
            f(s,i,mp,k,cnt);
        }
        return ans;
    }
};