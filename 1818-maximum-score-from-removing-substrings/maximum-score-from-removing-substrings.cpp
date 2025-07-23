class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ac = 0, bc = 0;
        int ans = 0;
        int n = s.size();
        char last = ' ';
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch=='a'){
                if(bc==0) {
                    ac++;
                    last = 'a';
                }
                else if(y>=x){
                    bc--;
                    ans += y;
                    if(bc==0) last = ' ';
                }else {
                    ac++;
                    last = 'a';
                }
            }else if(ch=='b'){
                if(ac==0) {
                    bc++;
                    last = 'b';
                }
                else if(x>=y) {
                    ac--;
                    ans += x;
                    if(ac==0) last = ' ';
                }else {
                    bc++;
                    last = 'b';
                }
            }else if(i>0){
                if(last=='b') ans += (min(ac,bc)*x);
                else if(last=='a') ans += (min(ac,bc)*y);
                ac = 0, bc = 0;
            }
        }
        if(last=='b') ans += (min(ac,bc)*x);
        else if(last=='a') ans += (min(ac,bc)*y);
        return ans;
    }
};