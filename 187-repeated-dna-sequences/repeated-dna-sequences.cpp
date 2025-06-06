class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        unordered_map<string,int>mp;
        vector<string>ans;
        for(int i=0; i<=n-10; i++){
            mp[s.substr(i,10)]++;
        }
        for(auto it:mp){
            if(it.second>1) ans.push_back(it.first);
        }
        return ans;
    }
};