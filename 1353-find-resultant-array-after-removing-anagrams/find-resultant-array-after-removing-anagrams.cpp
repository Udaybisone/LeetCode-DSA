class Solution {
    bool isAna(string w1,string w2){
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        return w1==w2;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        
        string w = words[0];
        vector<string>ans;
        for(int i=0; i<n-1; i++){
            if(!(isAna(words[i],words[i+1]))){
                ans.push_back(w);
                w = words[i+1];
            }
        }
        ans.push_back(w);
        return ans;
    }
};