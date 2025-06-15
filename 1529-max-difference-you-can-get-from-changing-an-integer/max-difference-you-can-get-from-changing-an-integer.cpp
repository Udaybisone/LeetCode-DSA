class Solution {
public:
    int maxDiff(int num) {
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
        
        if(s[0]=='1'){
            idx = 1;
            while(idx<n && (s[idx]=='0' || s[idx]=='1')) idx++;
            for(int i=idx+1; i<n; i++){
                if(s[i]==s[idx]) s[i] = '0';
            }
            if(idx<n) s[idx] = '0';
        }else{
            for(int i=1;i<n; i++){
                if(s[i]==s[0]) s[i] =  '1';
            }
            s[0] = '1';
        }

        int minnum = stoi(s);
        return maxnum - minnum;
    }
};