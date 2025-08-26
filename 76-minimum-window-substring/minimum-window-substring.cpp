class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        map<char,int>fs,ft;

        for(auto ch:t) ft[ch]++;
        int l = 0;
        int st = -1, len = INT_MAX;
        for(int r=0; r<n; r++){
            fs[s[r]]++;
            while(l<=r){
                bool b = false;
                for(auto it:ft){
                    if(it.second > fs[it.first]){
                        b = true;
                        break;
                    }
                }
                if(b) break;
                else{
                    if((r-l+1)<len){
                        st = l;
                        len = r-l+1;
                    }
                    fs[s[l]]--;
                    l++;
                }
            }
            
        }   
        if(st==-1) return "";
        return s.substr(st,len);
    }
};