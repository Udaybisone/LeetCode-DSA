class Solution {

public:
    long long validSubstringCount(string word1, string word2) {
        vector<int>f1(26,0);
        vector<int>f2(26,0);

        for(auto ch:word2){
            f2[ch-'a']++;
        }
        int n = word1.size();
        long long ans = 0,l = 0, r = 0;
        
        for(r=0; r<n; r++){
            f1[word1[r]-'a']++;

            while(true){
                bool isvalid = true;
                for(int i=0; i<26; i++){
                    if(f1[i]<f2[i]){
                        isvalid = false;
                        break;
                    }
                }
                if(isvalid){
                    ans += (n-r);
                    f1[word1[l]-'a']--;
                    l++;
                }else break;
            }
        }
        return ans;
    }
};