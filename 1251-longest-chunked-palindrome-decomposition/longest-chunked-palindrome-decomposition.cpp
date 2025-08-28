class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();

        int l=0 , r = n-1;
        string tp1 = "", tp2 = "";
        int ans = 0;
        while(l<r){
            tp1 += text[l];
            tp2 = text[r] + tp2;

            if(tp1 == tp2){
                ans += 2;
                tp1 = "";
                tp2 = "";
            }
            l++;
            r--;
        }

        if(l==r) ans++;
        else {
            if(tp1 != "") ans++;
        }
        return ans;
    }
};