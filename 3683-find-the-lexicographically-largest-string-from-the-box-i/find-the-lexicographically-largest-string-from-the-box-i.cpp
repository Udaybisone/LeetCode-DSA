class Solution {
public:
    string answerString(string word, int k) {
        string ans = "";
        int n = word.size();
        for(int i=0; i<n; i++){
            int k1 = k;
            k1 -= i;
            if(k1<=0) {
                if(k==1) continue;
                else k = 0;
            }
            
            if(ans == "") ans = word.substr(i,n-i-k1+1);
            else ans = max(ans,word.substr(i,n-i-k1+1));
        }
        return ans;
    }
};