class Solution {
    string f(string s){
        int n = s.size();
        int i = 0,j = 1;
        while(j<n){
            if(s[i]<s[j]){
                i = j;
                j++;
            }else if(s[i]>s[j]) j++;
            else{
                int ti = i, tj = j;
                while(tj<n && ti<j && s[ti]==s[tj]){
                    ti++,tj++;
                }
                if(ti<j && tj<n && s[ti]<s[tj]){
                    i = j;
                    j = tj;
                }else j = tj;
            }
        }
        return s.substr(i);
    }
public:
    string lastSubstring(string s) {
        string ans = f(s);
        while(s!=ans){
            s = ans;
            ans = f(s);
        }
        return ans;
    }
};