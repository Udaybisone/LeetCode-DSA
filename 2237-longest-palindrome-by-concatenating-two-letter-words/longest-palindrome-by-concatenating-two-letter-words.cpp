class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto w:words){
            mp[w]++;
        }
        int ans = 0;
        int f = 0;
        for(auto it:mp){
            string s1 = it.first, s2 = it.first;
            reverse(s2.begin(),s2.end());
            cout<<mp[s1]<<endl;
            if(s1==s2) {
                
                if(mp[s1]%2){
                    f = 1;
                    ans += (2*(mp[s1]-1));
                }else ans += (2*mp[s1]);
                mp[s1] = 0;
            }else{
                ans += (4*min(mp[s1],mp[s2]));
                mp[s1] = 0;
                mp[s2] = 0;
            }
        }
        // cout<<ans<<endl;
        return ans + ((f==1)?2:0);
    }
};