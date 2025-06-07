class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>>v(26);
        vector<int>del(n,0);
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                for(auto &v:v){
                    if(v.size()>0){
                        del[v.back()] = 1;
                        del[i] = 1;
                        v.pop_back();
                        break;
                    }
                }
            }else v[s[i]-'a'].push_back(i);
        }

        string res = "";
        for(int i=0; i<n; i++){
            if(!del[i]) res += s[i];
        }

        return res;
    }
};