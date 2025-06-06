class Solution {
public:
    string robotWithString(string s) {
        vector<int>freq(26,0);
        for(auto c:s) freq[c-'a']++;
        string t = "";
        int i = 0;
        string res = "";
        int n = s.size();
        while(i<n){
            int minchar = -1;
            for(int ch=0; ch<26; ch++){
                if(freq[ch]>0){
                    minchar = ch;
                    break;
                }
            }
            if(minchar==-1) break;
            if(t.size()==0 || minchar<(t.back()-'a')){
                while(i<n && freq[minchar]>0){
                    if((s[i]-'a')==minchar) {
                        res += s[i];
                        freq[minchar]--;
                    }
                    else {
                        t += s[i];
                        freq[s[i]-'a']--;
                    }
                    i++;
                }
            }else {
                res += t.back();
                t.pop_back();
            }
        }
        reverse(t.begin(),t.end());
        res += t;
        return res;
    }
};