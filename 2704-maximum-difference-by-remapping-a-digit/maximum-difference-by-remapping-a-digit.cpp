class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.size();
        int idx = -1;
        for(int i=0; i<n; i++){
            if(s[i]!='9' && idx==-1) idx = i;
            else if(idx!=-1){
                if(s[i]==s[idx]) s[i] = '9';
            }
        }
        if(idx!=-1) s[idx] = '9';
        int maxnum = stoi(s);
        s = to_string(num);
        for(int i=1; i<n; i++){
            if(s[i]==s[0]) s[i] = '0';
        }
        s[0] = '0';

        int minnum = stoi(s);
        return maxnum - minnum;
    }
};