class Solution {
    bool isvalid(int i,int j,vector<vector<int>>&freq,int k){
        int n = freq.size();

        for(int c=0; c<26; c++){
            int occ = freq[j][c] - ((i==0)?0:freq[i-1][c]);
            if(occ != 0 && occ<k){
                return false;
            }
        }
        return true;
    }
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0; i<n; i++){
            if(i!=0){
                for(int c=0; c<26; c++){
                    freq[i][c] = freq[i-1][c];
                }
            }
            freq[i][s[i]-'a']++;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=i; j--){
                if(isvalid(i,j,freq,k)){
                    ans = max(ans,j-i+1);
                    break;
                }
            }
        }
        return ans;
    }
};